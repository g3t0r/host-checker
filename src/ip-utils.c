#include "ip-utils.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

uint32_t ipv4fromString(const char *str)
{
    if(strlen(str) > 15) { // 4x3 numbers + 3 dots
        exit(1); 
    }
    short shift = 0;
    uint8_t octets[4]; // left to right order
    for(int oct = 1; oct <= 4; oct++) {
        int octInDec;
        if(oct != 4) {
            char* dotPointer;
            if((dotPointer = strchr(str + shift, '.')) == NULL) {
                exit(1);
            }
            int dotIndex = dotPointer - str;
            char * strOct = malloc(dotIndex - shift - 1);
            strncpy(strOct, str + shift, dotIndex);
            octInDec =  atoi(strOct);
            printf("Result: %d\n", octInDec);
            free(strOct);
            shift = dotIndex+1;
        } else {
            int distanceFromEnd = strlen(str) - shift + 1;
            char * strOct = malloc(distanceFromEnd);
            strncpy(strOct, str+shift, distanceFromEnd);
            octInDec = atoi(strOct);
            printf("Result: %d\n", octInDec);
            free(strOct);
        }
        octets[oct - 1] = octInDec;
    }

    return 0;
    
}


char *ipv4ToString(uint32_t ipv4)
{
    return 0;
}
