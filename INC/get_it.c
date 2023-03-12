#include "cube.h"

char    **get_it(void)
{
    char **(ptr) = malloc(sizeof(char *) * HEIGH);
    ptr[0] = strdup("   1111111111111111111\n");
    ptr[1] = strdup("   1000000100000000001\n");
    ptr[2] = strdup("   1000000100000001001\n");
    ptr[3] = strdup("   1111100000000001111\n");
    ptr[4] = strdup("1111  1000000000001\n");
    ptr[5] = strdup("1001  1000000000001\n");
    ptr[6] = strdup("1001  1000101111111\n");
    ptr[7] = strdup("1001111000101\n");
    ptr[8] = strdup("1000010000101\n");
    ptr[9] = strdup("1111000000111\n");
    ptr[10] = strdup("   1100000111111111111\n");
    ptr[11] = strdup("   1000000100000000001\n");
    ptr[12] = strdup("   1000000000000001001\n");
    ptr[13] = strdup("   1111100000000001111\n");
    ptr[14] = strdup("1111001000000000001\n");
    ptr[15] = strdup("1000001000000000001\n");
    ptr[16] = strdup("1001111000001111111\n");
    ptr[17] = strdup("1000000000N01\n");
    ptr[18] = strdup("1000000000001\n");
    ptr[19] = strdup("1111111111111\n");
    ptr[20] = NULL;
    return (ptr);
}
