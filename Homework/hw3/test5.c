#include <stdio.h>
int main()
{
    int row_num = 0;
    int col_num = 0;
    int hint_num = 0;
    scanf("%d%d%d",&row_num,&col_num,&hint_num);
    char drct[505][505];
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            getchar();
            scanf("%c",&drct[i][j]);
        }
    }
    int r_loc = 0;
    int c_loc = 0;
    scanf("%d%d",&r_loc,&c_loc);
    
    int loc[100005][2] = {0};
    loc[0][0] = r_loc;
    loc[0][1] = c_loc;
    char move_d[100005][7] = {0};
    int move_n = 0;
    int judge = 10;
    int move_d_num = 0;
    int drct_num = 0;
    getchar();
    for (int i = 0; i < hint_num && i < (row_num * col_num) - 1; i++)
    {
        scanf("%s %d",move_d[i],&move_n);
        getchar();
        switch (move_d[i][0])
        {
            case'F':move_d_num = 0;break;
            case'R':move_d_num = 1;break;
            case'B':move_d_num = 2;break;
            case'L':move_d_num = 3;break;
        }
        switch (drct[r_loc-1][c_loc-1])
        {
            case'U':drct_num = 0;break;
            case'R':drct_num = 1;break;
            case'D':drct_num = 2;break;
            case'L':drct_num = 3;break;

        }
        switch ((move_d_num + drct_num)%4)
        {
            case 0:r_loc -= move_n;break;
            case 1:c_loc += move_n;break;
            case 2:r_loc += move_n;break;
            case 3:c_loc -= move_n;break;
        }
        if (r_loc <= 0 || r_loc > row_num || c_loc <= 0 || c_loc > col_num)
        {
            judge = 0;
            break;
        }
        for (int j = 0; j < i+1; j++)
        {
            if (r_loc == loc[j][0] && c_loc == loc[j][1])
            {
                judge = 0;
                break;
            }
        }
        if (judge == 0)
        {
            break;
        }
        loc[i+1][0] = r_loc;
        loc[i+1][1] = c_loc;
        printf("(%d, %d)\n",loc[i+1][0],loc[i+1][1]);
    }
    if (judge == 0)
    {
        printf("Mistake!");
    }
    return 0;
}

