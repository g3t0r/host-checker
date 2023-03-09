#ifndef __IP_UTILS__
#define __IP_UTILS__

#include "stdint.h"

uint32_t ipv4fromString(const char * str);
char * ipv4ToString(uint32_t ipv4);

#endif