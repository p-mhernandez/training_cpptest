#ifndef TEST_SAMPLE_H
#define TEST_SAMPLE_H

#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"



struct allSensorState
{
	uint32_t on;
	uint32_t status;
};

typedef struct
{
	uint32_t radioID;
	uint32_t status;
}Info;

#endif
