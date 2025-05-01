#include <stdio.h>
#include <stdlib.h>

int *foo(void);

int main(void)
{
    int b = *(foo());
    printf("%i\n", b);
}

int *foo(void)
{
    int *a = malloc(sizeof(int));
    *a = 3;
    return a;
}

CHAR *S = "hi"(right)
int *x = 3(wrong)
int *x = malloc(int)
*x = 3(rihgt) or int b= 3, int *a = &b


