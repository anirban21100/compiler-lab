#include <stdio.h>
int main()
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (number % 2 == 0)
        printf("%d is even.", number);
    else
        printf("%d is odd.", number);
    return 0;
}
/*
 flex q3.l
 gcc .\lex.yy.c
 .\a.exe .\input.c
*/