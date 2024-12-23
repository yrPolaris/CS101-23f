#include <stdio.h>
int hw4_islower(int ch)
{
    return ch/97 & -((ch/123)-1);
}

int hw4_isupper(int ch)
{
    return ch/65 & -((ch/91)-1);
}

int hw4_isalpha(int ch)
{
    return (ch/97 & -((ch/123)-1)) | (ch/65 & -((ch/91)-1));
}

int hw4_isdigit(int ch)
{
    return 2*(ch/48 & -((ch/58)-1) & -((ch/100)-1));
}

int hw4_tolower(int ch)
{
    return ch + ((-'A') + 'a')*(ch/65 & -((ch/91)-1));
}

int hw4_toupper(int ch)
{
    return ch + ((-'a') + 'A')*(ch/97 & -((ch/123)-1));
}

size_t hw4_strlen(const char* str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i += 1;
    }
    return i;
}

char* hw4_strchr(const char* str, int ch)
{
    char *pos = (char *)str;
    while (*pos != (char)ch && *pos != '\0')
    {
        pos++;
    }
    if (*pos == ch)
    {
        return pos;
    }
    return NULL;
}

char* hw4_strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

char *hw4_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    while (dest[i] != 0)
    {
        i += 1;
    }
    while (dest[i] == 0 && src[j] != 0)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = src[j];
    return dest;    
}

int hw4_strcmp(const char *lhs, const char *rhs)
{
    int flag = 10;
    while (*lhs == *rhs && *lhs != 0 && *rhs != 0)
    {
        lhs++;
        rhs++;
    }
    if (*lhs > *rhs)
    {
        flag = 1;
    }
    else if (*lhs < *rhs)
    {
        flag = -1;
    }
    else if (*lhs == *rhs)
    {
        flag = 0;
    }
    return flag;
}
