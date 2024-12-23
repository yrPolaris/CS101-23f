#include <stdio.h>
#include <string.h>
int main()
{
    long long key;
    long long len = 0;
    char str[1000002] = {0};
    scanf("%lld",&key);
    getchar();
    scanf("%[^\n]",str);
    for (long long i = 0; i < 1000002; i++)
    {
        if (str[i] != 0)
        {
            len += 1;
        }
        else
        {
            break;
        }
    }
    if (key > 0)
    {
        for (long long i = 0; i < len; i++)
        {
            if (str[i] >= 48 && str[i] <= 57)
            {
                str[i] = str[i] - (key - ((key)/10)*10);
                if (str[i] <= 47)
                {
                    str[i] += 10;  
                }
            }
            else if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] = str[i] - (key - ((key)/26)*26);
                if (str[i] <= 64)
                {
                    str[i] += 26;
                }
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                str[i] = str[i] - (key - ((key)/26)*26);
                if (str[i] <= 96)
                {
                    str[i] += 26;
                }
            }
            else
            {
                str[i] = str[i];
            }
        }
    }
    if (key < 0)
    {
        for (long long i = 0; i < len; i++)
        {
            if (str[i] >= 48 && str[i] <= 57)
            {
                str[i] = str[i] - (key + ((-key)/10)*10);
                if (str[i] >= 58)
                {
                    str[i] -= 10;
                }
            }
            else if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] = str[i] - (key + ((-key)/26)*26);
                if (str[i] >= 91)
                {
                    str[i] -= 26;
                }
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                
                if ((str[i] - (key + ((-key)/26)*26)) >= 123 && (str[i] - (key + ((-key)/26)*26)) < 127)
                {
                    str[i] = str[i] - (key + ((-key)/26)*26);
                    str[i] -= 26;
                }
                else if ((str[i] - (key + ((-key)/26)*26)) >= 127)
                {
                    str[i] = str[i] - (key + ((-key)/26)*26) - 26;
                }
                else
                {
                    str[i] = str[i] - (key + ((-key)/26)*26);
                }
            }
            else
            {
                str[i] = str[i];
            }
        }
    }
    for (long long i = 0; i < len; i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}