#include "linux_kernel_micro.h"
#include <stdio.h>

struct test_struct{
    char ch; // 1bype
    int num; // 1byte
    char chs[3]; //1bype
    char *ptr;
};

#define print_str(str) printf(#str)

#define print_offsetof_member(type, member) {   \
    printf("offsetof(%s, %s) = %d\n",           \
#type, #member,                                 \
            (int)offsetof(type, member));       \
}


int main()
{
    print_str(hello world.\n);
    print_offsetof_member(struct test_struct, ch);
    print_offsetof_member(struct test_struct, num);
    print_offsetof_member(struct test_struct, chs);
    print_offsetof_member(struct test_struct, ptr);

    printf("sizeof(struct test_struct) is %d\n", (int)sizeof(struct test_struct));
    return 0;
}



