#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void sig_handler_ctrl_c(int  sig_type)
{
    printf("main send %d signal\n", sig_type);
    printf("you enter Ctrl + C here.\n");
    printf("do  your signal handling below.\n");

    printf("here just print out some notes, do nothing.\n");
    (void)signal(SIGINT, SIG_DFL);
}

int main()
{
    (void)signal(SIGINT, sig_handler_ctrl_c);
    printf("The main() function is forever-loop...\n");
    while(1) {
        printf("Press CRTL + C to break this loop\n");
        sleep(2);
    }

    exit(EXIT_SUCCESS);
}
