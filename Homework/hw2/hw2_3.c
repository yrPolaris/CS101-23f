#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char symbol;
    char char1[52] = {0}, char2[52] = {0};
    int num1[52] = {0}, num2[52] = {0}, num[52] = {0};
    int ls1, ls2, ls;
    scanf("%c",&symbol);
    scanf("%s",char1);
    scanf("%s",char2);
    ls1 = strlen(char1); 
    ls2 = strlen(char2);
    ls = fmax(ls1,ls2);
    int count = 0;
    for (int i = 0; i < ls1; i++)
    {
        if (char1[i] < 97)
        {
            num1[ls1 - i - 1] = char1[i] - 48;
        }
        else
        {
            num1[ls1 - i - 1] = char1[i] - 87;
        }
    }
    for (int i = 0; i < ls2; i++)
    {
        if (char2[i] < 97)
        {
            num2[ls2 - i - 1] = char2[i] - 48;
        }
        else
        {
            num2[ls2 - i - 1] = char2[i] - 87;
        }
    }
    if (symbol == '+')
    {
        for (int i = 0; i < ls; i++)
        {
            num[ls - i - 1] = num1[i] + num2[i];
            if (i >= 1 && num[ls - i] >= 16)
            {
                num[ls - i] = num[ls - i] - 16;
                num[ls - i - 1] = num[ls - i - 1] + 1;
            }
        }
    }
    if (symbol == '-')
    {
        for (int i = 0; i < ls; i++)
        {
            num[ls - i - 1] = num1[i] - num2[i];
            if (i >= 1 && num[ls - i] < 0)
            {
                num[ls - i] = num[ls - i] + 16;
                num[ls - i - 1] = num[ls - i - 1] - 1;
            }
        }
    }
    for (int i = ls - 1; i > -1; i--)
    {
        if (0 <= num[i] && num[i] < 10)
        {
            num[i] = num[i] + 48;
        }
        if (num[i] >= 10 && num[i] < 16)
        {
            num[i] = num[i] + 87;
        }
    }
    for (int i = 0; i < ls; i++)
    {
        if (num[i] == 48)
        {
            count += 1;
        }
        if (num[i] != 48)
        {
            break;
        }
    }
    for (int i = 0; i < ls + 1 - ls1; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < ls1; i++)
    {
        printf("%c", char1[i]);
    }
    printf("\n");
    printf("%c", symbol);
    for (int i = 0; i < ls - ls2; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < ls2; i++)
    {
        printf("%c", char2[i]);
    }
    printf("\n");
    for (int i = 0; i < ls + 1; i++)
    {
        printf("-");
    }
    printf("\n");
    if (count == ls)
    {
        for (int i = 0; i < count; i++)
        {
            printf(" ");
        }
        printf("0");
    }
    if (count < ls)
    {
        for (int i = 0; i < count + 1; i++)
        {
            printf(" ");
        }
    }
    for (int i = count; i < ls; i++)
    {
        printf("%c", num[i]);
    }
    return 0;
}