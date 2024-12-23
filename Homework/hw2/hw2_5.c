#include <stdio.h>

int checkpalace(int (*ar)[9])
{
    int count = 1;
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            if (ar[i][j] == ar[i+1][j+1] || ar[i][j] == ar[i+2][j+2])
            {
                count = 0;
            }
            if (ar[i+2][j] == ar[i+1][j+1] || ar[i][j] == ar[i][j+2])
            {
                count = 0;
            }
            if (ar[i][j+1] == ar[i+1][j+2] || ar[i][j+1] == ar[i+1][j])
            {
                count = 0;
            }
            if (ar[i+2][j+1] == ar[i+1][j+2] || ar[i+2][j+1] == ar[i+1][j])
            {
                count = 0;
            }
        }
    }
    return count;
}

int checkrow(int (*ar)[9])
{
    int count = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = j; k < 8; k++)
            {
                if (ar[i][j] == ar[i][k+1])
                {
                    count = 0;
                }
            }
        }
    }
    return count;
}

int checkcol(int (*ar)[9])
{
    int count = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = j; k < 8; k++)
            {
                if (ar[j][i] == ar[k+1][i])
                {
                    count = 0;
                }
            }
        }
    }
    return count;
}

int checkhrow(int (*ar)[9])
{
    int count = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (ar[i][j] == ar[i+1][j+2])
            {
                count = 0;
            }
        }
    }
    for (int i = 8; i > 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
            if (ar[i][j] == ar[i-1][j+2])
            {
                count = 0;
            }
        }
    }
    return count;
}

int checkhcol(int (*ar)[9])
{
    int count = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (ar[i][j] == ar[i+2][j+1])
            {
                count = 0;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 8; j > 0; j--)
        {
            if (ar[i][j] == ar[i+2][j-1])
            {
                count = 0;
            }
        }
    }
    return count;
}

int main()
{
    int ar[9][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        scanf("%d%d%d%d%d%d%d%d%d", &ar[i][0],&ar[i][1],&ar[i][2],&ar[i][3],&ar[i][4],&ar[i][5],&ar[i][6],&ar[i][7],&ar[i][8]);
    }
    int a,b,c,d,e;
    a = checkrow(ar);
    b = checkcol(ar);
    c = checkhrow(ar);
    d = checkhcol(ar);
    e = checkpalace(ar);
    if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
} 