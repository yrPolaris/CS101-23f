#include <stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    long long ar1[100];
    int count = 0;
    for (int i = 0; i < num; i++){
        scanf("%lld", &ar1[i]);
    }
    for (int i = 0; i < num; i++){
        if (ar1[i] > 0){
            count++;
            ar1[i] = (long long)ar1[i] * (long long)ar1[i];
        }    
    }
    for (int i = num - 1; i > -1; i--){
        if (ar1[i] > 0){
            printf("%lld\n", ar1[i]);
        }    
    }
    printf("%d", count);
    return 0;
}