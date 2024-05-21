#include "testedFunctions.h"
#include "externalFunctions.h"

uint32_t saveReg1, saveReg2, saveReg3;
static uint32_t static_int_variable;
const uint32_t R1 = 11;
const uint32_t R2 = 22;
const uint32_t R3 = 44;

static int multipleCalls(Info* pResult);
static void infiniteLoop(int c);

int foo();

/**
 * Simple addition
 */
uint32_t add(uint32_t a, uint32_t b)
{
//	foo();
	return a+b;
}

/************************
 * Conditional addition
 * R1 = 11, R2 = 22
 ************************/
uint32_t conditional_add(uint32_t a, uint32_t b, uint32_t condition)
{
	uint32_t ret = 0;

	if((condition < R2) && (condition >= R1))
	{
		ret = add(a,b);
	}

	static_int_variable = ret;
	return ret;
}
/*********************
 *
 * update struct values.
 *
 *********************/
static void updateStruct(uint16_t updateMsgType, struct allSensorState *as) {

	switch (updateMsgType) {

	case 0:
		as->on = 0;
		as->status = 1;
		break;
	case 1:
		as->on = 1;
		as->status = 1;
		break;
	default:
		as->on = 0;
		as->status = 0xBADF00D;
		break;
	}
}
/************************
 *
 * call to a blocking function.
 *
 ************************/
uint32_t callToNoReturn(uint32_t a, uint32_t b, uint32_t condition)
{
	uint32_t ret = 0;

	if(condition > 1)
	{

		infiniteLoop(a);
		ret = add(a,b);
	}
	return ret;
}

/****************************************
 *
 * Modify input, call a function, check return
 * Stubbed function is internal to compilation unit
 *
 ***************************************/
static uint32_t modifyStructValuesConditionalReturn(Info* pResult) {
	uint32_t ret = 0;
	//modifying input
	if (0 == multipleCalls(pResult)) {
		pResult->radioID = 7;
		pResult->status = 3;
		ret = 1;
	} else {
		pResult->radioID = 8;
		pResult->status = 21;
		ret = 2;
	}
	return ret;
}
/*******************************************
 *
 * Modify input params
 * Modify return value to exit busy wait
 *
 * Stubbed function is an external function.
 *
 ********************************************/
static void modifyStructValuesBusyWait(struct sharedMsg *sMsg,
		struct allSensorState *as) {
	uint32_t rc = 0;
	sMsg->msg = "Bad Morning\n";
	sMsg->size = strlen(sMsg->msg);
	if (1 == as->on) {
		do {
			rc = sharedQueuePend(sMsg, 1);
		} while (rc == 0);
	}
}



/************************************************
 *
 * Multiple calls to the same function
 * Verify logic for every call.
 * Control the return parameter based on the callNo variable in the stub
 *
 ************************************************/
static int multipleCalls(Info* pResult) {
	int rc = 0;

	rc = GetRegSingle(R1, &saveReg1);

	if (rc) {
		goto exit;
	}

	rc = GetRegSingle(R2, &saveReg2);

	if (rc) {
		goto exit;
	}

	rc = GetRegSingle(R3, &saveReg3);

	if (rc) {
		goto exit;
	}

	exit: return rc;
}

/***********************************
 * Infinite loop
 **********************************/
static void infiniteLoop(int c) {
	c++;
	while (1) {
		c++;
	}
	c--;
}


