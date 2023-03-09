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
        int stringOctetSize;
        int shiftUpdate = shift;

        if(oct != 4) {
            char* dotPointer;
            if((dotPointer = strchr(str + shift, '.')) == NULL) {
                exit(1);
            }

            int dotIndex = dotPointer - str;

            stringOctetSize = dotIndex - shift;
            shiftUpdate = dotIndex+1;
        } else {
            stringOctetSize = strlen(str) - shift + 1;
        }
        char * strOct = malloc(stringOctetSize);
        strncpy(strOct, str + shift, stringOctetSize);
        octInDec =  atoi(strOct);
        free(strOct);
        shift = shiftUpdate;
        printf("%d\n", octInDec);
        octets[oct - 1] = octInDec;
    }

    return 0;
    
}


char *ipv4ToString(uint32_t ipv4)
{
    return 0;
}
