#ifndef EXTERN_H
#define EXTERN_H

#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"

void initExternal(uint32_t val);
void externalFunction1(void);
struct sharedMsg
{
	uint32_t size;
	char* msg;
};

uint32_t sharedQueuePend(struct sharedMsg *sMsg, uint32_t s);

uint32_t GetRegSingle(uint32_t regID, uint32_t* reg);


#endif
