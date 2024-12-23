#include <stdio.h>
int main()
{
    long  num = 0;
    scanf("%ld",&num);

    static char name[10000001] = {0};
    int price_temp = 0;
    int  type_temp = 0;
    static int  price[1003] = {0};
    static int  type = 0;

    for (int i = 0; i < num; i++)
    {
        scanf("%[^,]",name);
        getchar();
        scanf("%d[^,]",&price_temp);
        getchar();
        scanf("%d[^)]",&type_temp);
        getchar();
        price[type_temp - 1] += price_temp;
    }
    for (int i = 0; i < num; i++)
    {
        if (price[i] >= price[type])
        {
            type = i;
            price[1001] = type+1;
        }
    }
    printf("%d",price[1001]);
    return 0;   
}