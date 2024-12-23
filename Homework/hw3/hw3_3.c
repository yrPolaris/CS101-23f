#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int mth = 0;
    scanf("%d",&mth);
    int ar_d[200] = {0};
    for (int i = 0; i < mth; i++)
    {
        scanf("%d",&ar_d[i]);
    }


    char temp1[20] = {0};
    char temp2[20] = {0};
    char ar_y[10002][5] = {0};
    scanf("%s",temp1);
    scanf("%s",temp2);
    int len = 0;
    len = (int)(temp2[3]-temp1[3]) + ((int)(temp2[2]-temp1[2]))*10 + ((int)(temp2[1]-temp1[1]))*100 + ((int)(temp2[0]-temp1[0]))*1000 + 1;
    int year = 0;
    year = (int)(temp1[3]-48) + ((int)(temp1[2]-48))*10 + ((int)(temp1[1]-48))*100 + ((int)(temp1[0]-48))*1000;
    for (int i = 0; i < len; i++)
    {
        ar_y[i][0] = (year/1000) + '0';
        ar_y[i][1] = ((year/100)%10) + '0';
        ar_y[i][2] = ((year%100)/10) + '0';
        ar_y[i][3] = (year%10) + '0';
        year += 1;
    }


    int count = 0;
    if ((((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)) == (mth))
    {
        if ((((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) <= ar_d[mth-1] && (((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) > 0)
        {
            count += 1;
        }
    }
    else if((((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)) == (((int)(temp1[4]-48))*10 + (int)(temp1[5]-48)))
    {
        if ((((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) <= ar_d[(((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)) - 1] && (((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) >= (((int)(temp1[6]-48))*10 + (int)(temp1[7]-48)))
        {
            count += 1;
        }
    }
    else if((((int)(temp1[4]-48))*10 + (int)(temp1[5]-48)) < (((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)) && mth > (((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)))
    {
        if ((((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) <= ar_d[(((int)(ar_y[0][3]-48))*10 + (int)(ar_y[0][2]-48)) - 1] && (((int)(ar_y[0][1]-48))*10 + (int)(ar_y[0][0]-48)) > 0)
        {
            count += 1;
        }
    }
    else
    {
        count = count;
    }

    if ((((int)(ar_y[len - 1][3]-48))*10 + ((int)(ar_y[len - 1][2]-48))) < (((int)(temp2[4]-48))*10 + (int)(temp2[5]-48)) && (((int)(ar_y[len - 1][3]-48))*10 + ((int)(ar_y[len - 1][2]-48))) > 0)
    {
        if ((((int)(ar_y[len - 1][1]-48))*10 + (int)(ar_y[len - 1][0]-48)) <= ar_d[(((int)(ar_y[len - 1][3]-48))*10 + (int)(ar_y[len - 1][2]-48)) - 1] && (((int)(ar_y[len - 1][1]-48))*10 + (int)(ar_y[len - 1][0]-48)) > 0)
        {
            count += 1;
        }
    }
    else if ((((int)(ar_y[len - 1][3]-48))*10 + (int)(ar_y[len - 1][2]-48)) == (((int)(temp2[4]-48))*10 + ((int)(temp2[5]-48))))
    {
        if ((((int)(ar_y[len - 1][1]-48))*10 + (int)(ar_y[len - 1][0]-48)) <= (((int)(temp2[6]-48))*10 + (int)(temp2[7]-48)) && (((int)(ar_y[len - 1][1]-48))*10 + (int)(ar_y[len - 1][0]-48)) > 0)
        {
            count += 1;
        }
    }
    else
    {
        count = count;
    }

    for (int i = 1; i < len-1; i++)
    {
        if ((((int)(ar_y[i][3]-48))*10 + (int)(ar_y[i][2]-48)) <= (mth) && (((int)(ar_y[i][3]-48))*10 + (int)(ar_y[i][2]-48)) > 0)
        {
            if ((((int)(ar_y[i][1]-48))*10 + (int)(ar_y[i][0]-48)) <= ar_d[(((int)(ar_y[i][3]-48))*10 + (int)(ar_y[i][2]-48)) - 1] && (((int)(ar_y[i][1]-48))*10 + (int)(ar_y[i][0]-48)) > 0)
            {
                count += 1;
            }
        }
    }


    printf("%d",count);
    return 0;
}