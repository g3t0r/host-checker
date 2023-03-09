#include "error-handling.h"
#include "stdio.h"

void printAndQuit(const char *msg)
{
    printf("[ERROR] %s\n", msg);
    exit(1);
}