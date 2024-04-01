#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pm();
void plus();
void divison();
int i, ch, j, l, addr = 100;
char ex[10], arr[10], arr1[10], arr2[10], id1[5], op[5], id2[5];
void main()
{
    while (1)
    {
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the arrression with assignment operator:");
            scanf("%s", arr);
            l = strlen(arr);
            arr2[0] = '\0';
            i = 0;
            while (arr[i] != '=')
            {
                i++;
            }
            strncat(arr2, arr, i);
            strrev(arr);
            arr1[0] = '\0';
            strncat(arr1, arr, l - (i + 1));
            strrev(arr1);
            printf("Three address code:\ntemp=%s\n%s=temp\n", arr1, arr2);
            break;

        case 2:
            printf("\nEnter the arrression with arithmetic operator:");
            scanf("%s", ex);
            strcpy(arr, ex);
            l = strlen(arr);
            arr1[0] = '\0';

            for (i = 0; i < l; i++)
            {
                if (arr[i] == '+' || arr[i] == '-')
                {
                    if (arr[i + 2] == '/' || arr[i + 2] == '*')
                    {
                        pm();
                        break;
                    }
                    else
                    {
                        plus();
                        break;
                    }
                }
                else if (arr[i] == '/' || arr[i] == '*')
                {
                    divison();
                    break;
                }
            }
            break;

        case 3:
            printf("Enter the arrression with relational operator");
            scanf("%s%s%s", &id1, &op, &id2);
            if (((strcmp(op, "<") == 0) || (strcmp(op, ">") == 0) || (strcmp(op, "<=") == 0) || (strcmp(op, ">=") == 0) || (strcmp(op, "==") == 0) || (strcmp(op, "!=") == 0)) == 0)
                printf("arrression is error");
            else
            {
                printf("\n%d\tif %s%s%s goto %d", addr, id1, op, id2, addr + 3);
                addr++;
                printf("\n%d\t T:=0", addr);
                addr++;
                printf("\n%d\t goto %d", addr, addr + 2);
                addr++;
                printf("\n%d\t T:=1", addr);
            }
            break;
        case 4:
            exit(0);
        }
    }
}
void pm()
{
    strrev(arr);
    j = l - i - 1;
    strncat(arr1, arr, j);
    strrev(arr1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", arr1, arr[j + 1], arr[j]);
}
void divison()
{
    strncat(arr1, arr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", arr1, arr[i + 2], arr[i + 3]);
}
void plus()
{
    strncat(arr1, arr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", arr1, arr[i + 2], arr[i + 3]);
}
