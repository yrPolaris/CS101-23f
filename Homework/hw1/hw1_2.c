#include <stdio.h>
#include <math.h>
int main()
{
    double k, b;
    int x1, x2, y1, y2;
    scanf("(%d, %d)\n",&x1, &y1);
    scanf("(%d, %d)",&x2, &y2);
    if(x1 == x2){
        printf("x = %.2f",(double)x1);
    }
    else{
        k = (double)(y1 - y2)/(double)(x1 - x2);
        if(k == abs(k))
        {
            k = abs(k);
        }
        b = y1 - k*x1;
        if(b >= 0){
            printf("y = %.2fx + %.2f",k,b);
        }
        else{
            printf("y = %.2fx - %.2f",k,-b);
        }
    }
    return 0;
}