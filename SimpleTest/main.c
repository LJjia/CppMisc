#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int tmp=0;
    printf(" Addr %p\n",&tmp);
    {
        int tmp=1;
        printf(" Addr %p\n",&tmp);
    }
    return 0;
}

