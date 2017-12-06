#include <stdlib.h>
#include <stdio.h>

int func1(int x, int y)
{
    int z = x * y;
    return z;
}

int func2(int x, int y)
{
    int z = func1(x + y, y);
    return z;
}

int main()
{
    int z = func2(4, 2);
    printf("z = %d\n", z);
    return 0;
}
