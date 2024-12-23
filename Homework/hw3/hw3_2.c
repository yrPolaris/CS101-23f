#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    // Process the keyword
    char keyword[200] = {0};
    int len = 0;
    scanf("%s",keyword);
    len = strlen(keyword);
    getchar();
    for (int i = 0; i < len; i++)
    {
        keyword[i] = tolower(keyword[i]);
    }
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (keyword[i] == keyword[j])
            {
                for (int k = j; k < len-1; k++)
                {
                    keyword[k] = keyword[k+1];
                }
                len--;
                j--;
            }
        }
    }

    // Establish and process the two arrays of corret order and encrypted order.
    char ls1[100] = "a";
    char ls2[100] = {0};
    int number = 1;
    for (int i = 0; i < 26; i++)
    {
        ls1[i] = ls1[0]+i;
        ls1[i+26] = ls1[i]-32;
    }
    for (int i = 0; i < len; i++)
    {
        ls2[i] = keyword[i];
        ls2[i+26] = keyword[i]-32;
    }
    for (int i = 0; i < 26-len; i++)
    {
        if (ls2[len-1]+number > 122)
        {
            if (strchr(keyword,ls2[len-1]+number-26) != NULL)
            {
                number += 1;
                i -= 1;
            }
            else
            {
                ls2[len+i] = ls2[len-1] + number-26;
                ls2[len+i+26] = ls2[len+i] - 32;
                number += 1;
            }
        }
        if (ls2[len-1]+number <= 122)
        {
            if (strchr(keyword,ls2[len-1]+number) != NULL)
            {
                number += 1;
                i -= 1;
            }
            else
            {
                ls2[len+i] = ls2[len-1] + number;
                ls2[len+i+26] = ls2[len+i] - 32;
                number += 1;
            }
        }
    }

    // Read the text and by index, decode the encrpted text
    char str[1000002] = {0};
    long long ls = 0;
    scanf("%[^\n]",str);
    ls = strlen(str);

    for (long long i = 0; i < ls; i++)
    {
        if (strchr(ls2,str[i]) != NULL)
        {
            printf("%c",ls1[strchr(ls2,str[i]) - ls2]);
        }
        if (strchr(ls2,str[i]) == NULL)
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}