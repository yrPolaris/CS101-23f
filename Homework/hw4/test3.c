#include <stdio.h>
int main()
{   
    int loc_ar[10] = {0};
    int i = 10;
    int *num = &i;
    loc_ar[1] = *num;
    *num = 8;
    printf("%d",loc_ar[1]);
    return 0;
}