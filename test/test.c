#include <stdio.h>
char *ptr_tostring(void *ptr)
{
        int i;
        unsigned char *s = (unsigned char *) &ptr;

        for (i = 0; i < 8; i++)
        {
                printf("%u\n", s[i]);
        }
        return "";
}
int main() {
    // Write C code here
    ptr_tostring((void *)-1);

    return 0;
}
