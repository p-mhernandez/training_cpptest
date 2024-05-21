#include "externalFunctions.h"

uint32_t globalVariable1;
uint32_t globalVariable2;

void initExternal(uint32_t val)
{
	globalVariable1 = val;
	globalVariable2 = val;
}

void externalFunction1(void)
{
	globalVariable1++;
	globalVariable2+=globalVariable1;
	return;
}

uint32_t sharedQueuePend(struct sharedMsg *sMsg, uint32_t s)
{
	return 0;
}

uint32_t GetRegSingle(uint32_t regID, uint32_t* reg)
{
	return 0;
}
