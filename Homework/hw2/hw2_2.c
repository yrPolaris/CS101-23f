#include <stdio.h>
#include <math.h>
int main()
{
    float x1;
    float x2;
    float x;
    double a, b, c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("x\\in\\mathbb{R}");
            }
            else
            {
                printf("No solution.");
            }
        }
        else{
            x = -(c/b);
            if (x == 0.000)
            {
                x = 0.000;
            }
            printf("x = %.3f", x);
        }
    }
    else
    {
        if (b*b - 4*a*c > 0)
        {
            x1 = ((-b)+sqrt(b*b - 4*a*c))/(2*a);
            x2 = ((-b)-sqrt(b*b - 4*a*c))/(2*a);
            if (x1 > x2)
            {
                if (x1 == 0.000)
                {
                    x1 = 0.000;
                }
                if (x2 == 0.000)
                {
                    x2 = 0.000;
                }
                printf("x1 = %.3f, x2 = %.3f",x2, x1);
            }
            else
            {
                printf("x1 = %.3f, x2 = %.3f",x1, x2);
            }
        }
        else if (b*b - 4*a*c == 0)
        {
            x1 = (-b)/(2*a);
            if (x1 == 0.000)
            {
                x1 = 0.000;
            }
            printf("x1 = x2 = %.3f",x1);
        }
        else
        {
            printf("No solution.");
        }
    }
    return 0;
}