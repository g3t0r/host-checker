#include "ip-utils.h"
#include "stdio.h"

int main() {
    uint32_t ip = ipv4fromString("192.168.0.1");
    uint32_t mask = ipv4fromString("255.255.255.0");


    printf("IP: %u\nMASK: %u\n", ip, mask);

    char * asString = ipv4ToString(ip);
    printf("IP as string: %s\n", asString);
    
    return 0;
}