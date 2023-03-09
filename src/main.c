#include "ip-utils.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Correct usage: host-checker [32bit-IP] [32-bit mask]\n");
        exit(1);
    }

    uint32_t ip = ipv4fromString(argv[1]);
    uint32_t mask = ipv4fromString(argv[2]);
    uint32_t networkIp = ip & mask;
    uint32_t broadcastIp = networkIp | ~mask;
    printf("IP: ");
    printIp(ip);

    printf("Mask: ");
    printIp(mask);

    printf("Network: ");
    printIp(networkIp);

    printf("Broadcast: ");
    printIp(broadcastIp);
    
    return 0;
}