#include "ip-utils.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"


uint8_t * extractOctetsFromInt(uint32_t ipv4) {
    uint8_t * octets = malloc(sizeof(uint8_t) * 4);
    for(int i = 0; i < 4; i++) {
        uint8_t octet = (ipv4 << (i * 8)) >> 24;
        octets[i] = octet;

    }
    return octets;
}

char *ipv4ToString(uint32_t ipv4)
{
    char * strIp = calloc(sizeof(char), 16); // 16 - 4x3 + 3 dots + terminating null
    uint8_t * octets = extractOctetsFromInt(ipv4);
    int shift = 0;
    for(int i = 0; i < 3; i++) {
        shift += sprintf(strIp + shift, "%u.", octets[i]);
    }
    shift += sprintf(strIp + shift, "%u.", octets[3]);
    strIp[shift] = '\0';
    free(octets);
    return strIp;
}

uint32_t convertOctetsToInt(uint8_t * octets) {
    uint32_t combined = 0;
    for(int i = 0; i < 3; i++) {
        combined += octets[i];
        combined <<= 8;
    }
    combined += octets[3];
    return combined;
}

uint8_t * extractOctets(const char *str) {
    if(strlen(str) > 15) { // 4x3 numbers + 3 dots
        exit(1); 
    }
    short shift = 0;
    uint8_t * octets =  malloc(sizeof(uint8_t) * 4); // left to right order
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
        octets[oct - 1] = octInDec;
    }

    return octets;
}

uint32_t ipv4fromString(const char *str)
{
    uint8_t * octets = extractOctets(str);
    uint32_t converted = convertOctetsToInt(octets);
    free(octets);
    return converted;
}


