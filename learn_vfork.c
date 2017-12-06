#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 6;

void test();
void do_vfork()
{
    pid_t pid;

    if((pid = vfork())< 0)
        perror("vfork");
    else if(pid == 0){
        test();
        printf("child: pid = %d.\n", getpid());
        return;
    } else {
        test();
        printf("parent: pid = %d.\n", getpid());
    }
}

void test()
{
    int i = 0;
    int buf[100];

    for(; i < 100; i++)
    {
        buf[i] = i;
        if(i == 0)
            printf("buf[100]: \n");
        printf("%5d", i);
        if((i + 1) % 10 == 0)
            printf("\n");
    }
    putchar('\n');
    printf("pid = %d.\n", getpid());
}

int main()
{
    do_vfork();
    return 0;
}
