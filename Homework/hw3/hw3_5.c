#include <stdio.h>
void F(int *row,int *col,int row_num,int move_n[100005],int *num,int loc[100005][2])
{
    *row -= move_n[*num];
    if (*row <= 0 || *row > row_num)
    {
        *row = -1;
    }
    else
    {
        for (int j = 0; j < *num+1; j++)
        {
            if (*row == loc[*num][0] && *col == loc[*num][1])
            {
                *row = -1;
            }
            else
            {
                loc[*num+1][0] = *row;
                loc[*num+1][1] = *col;
            }
        }
    }
}
void B(int *row,int *col,int row_num,int move_n[100005],int *num,int loc[100005][2])
{
    *row += move_n[*num];
    if (*row > row_num || *row <= 0)
    {
        *row = -1;
    }
    else
    {
        for (int j = 0; j < *num+1; j++)
        {
            if (*row == loc[j][0] && *col == loc[j][1])
            {
                *row = -1;
            }
            else
            {
                loc[*num+1][0] = *row;
                loc[*num+1][1] = *col;
            }
        }
    }
}
void R(int *row,int *col,int col_num,int move_n[100005],int *num,int loc[100005][2])
{
    *col += move_n[*num];
    if (*col > col_num || *col <= 0)
    {
        *row = -1;
    }
    else
    {
        for (int j = 0; j < *num+1; j++)
        {
            if (*row == loc[j][0] && *col == loc[j][1])
            {
                *row = -1;
            }
            else
            {
                loc[*num+1][0] = *row;
                loc[*num+1][1] = *col;
            }
        }
    }
}
void L(int *row,int *col,int col_num,int move_n[100005],int *num,int loc[100005][2])
{
    *col -= move_n[*num];
    if (*col <= 0 || *col > col_num)
    {
        *row = -1;
    }
    else
    {
        for (int j = 0; j < *num+1; j++)
        {
            if (*row == loc[j][0] && *col == loc[j][1])
            {
                *row = -1;
            }
            else
            {
                loc[*num+1][0] = *row;
                loc[*num+1][1] = *col;
            }
        } 
    }
}






int main()
{
    int row_num = 0;
    int col_num = 0;
    int hint_num = 0;
    int count = 0;
    scanf("%d%d%d",&row_num,&col_num,&hint_num);
    getchar();
    count = hint_num;


    char drct[505][505];
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            scanf("%c",&drct[i][j]);
            getchar();
        }
    }


    int r_lding = 0;
    int c_lding = 0;
    scanf("%d%d",&r_lding,&c_lding);
    int loc[100005][2] = {0};
    loc[0][0] = r_lding;
    loc[0][1] = c_lding;


    char move_d[100005][10] = {0};
    static int move_n[100005] = {0};

    int *row = &r_lding;
    int *col = &c_lding;
    for (int i = 0; i < hint_num; i++)
    {
        scanf("%s",move_d[i]);
        scanf("%d",&move_n[i]);
    }
    for (int i = 0; i < hint_num; i++)
    {
        int *num = &i;
        if (move_d[i][0] == 'F')
        {
            if (drct[*row-1][*col-1] == 'U')
            {
                F(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'D')
            {
                B(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'R')
            {
                R(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'L')
            {
                L(row,col,col_num,move_n,num,loc);
            }
            else
            {
                loc[0][0] = loc[0][0];
            }
        }
        else if (move_d[i][0] == 'B')
        {
            if (drct[*row-1][*col-1] == 'U')
            {
                B(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'D')
            {
                F(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'R')
            {
                L(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'L')
            {
                R(row,col,col_num,move_n,num,loc);
            }
            else
            {
                loc[0][0] = loc[0][0];
            }
        }
        else if (move_d[i][0] == 'R')
        {
            if (drct[*row-1][*col-1] == 'U')
            {
                R(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'D')
            {
                L(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'R')
            {
                B(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'L')
            {
                F(row,col,row_num,move_n,num,loc);
            }
            else
            {
                loc[0][0] = loc[0][0];
            }
        }
        else if (move_d[i][0] == 'L')
        {
            if (drct[*row-1][*col-1] == 'U')
            {
                L(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'D')
            {
                R(row,col,col_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'R')
            {
                F(row,col,row_num,move_n,num,loc);
            }
            else if (drct[*row-1][*col-1] == 'L')
            {
                B(row,col,row_num,move_n,num,loc);
            }
            else
            {
                loc[0][0] = loc[0][0];
            }
        }
        else
        {
            loc[0][0] = loc[0][0];
        }
        
        if (*row == -1)
        {
            break;
        }

        count -= 1;
        if ((hint_num - count) == (row_num*col_num)-1)
        {
            break;
        }
        if (count == 0)
        {
            break;
        }
    }
    for (int i = 1; i < hint_num - count+1; i++)
    {
        printf("(%d, %d)\n",loc[i][0],loc[i][1]);
    }
    if (*row == -1)
    {
        printf("Mistake!");
    }
    return 0;
}