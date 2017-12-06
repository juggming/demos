#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void charatatime(char *str);

int main()
{
    pid_t pid;
    if((pid = (fork())) < 0)
        perror("fork");
    else if(pid == 0) {
        charatatime("output from child.\n");
    } else {
        charatatime("output from parent.\n");
    }
    exit(0);
}

static void charatatime(char *str)
{
    assert(str);
    char *ptr = str;;

    setbuf(stdout, NULL);
    while(*ptr) {
        putchar(*ptr++);
    }
}
