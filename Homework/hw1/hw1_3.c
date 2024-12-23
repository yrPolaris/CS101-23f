#include <stdio.h>
void num2eng(int num)
{
    if(num >= 100){
        switch((int)num/100){
            case 1:
                printf("one hundred");
                break;
            case 2:
                printf("two hundred");
                break;
            case 3:
                printf("three hundred");
                break;
            case 4:
                printf("four hundred");
                break;
            case 5:
                printf("five hundred");
                break;
            case 6:
                printf("six hundred");
                break;
            case 7:
                printf("seven hundred");
                break;
            case 8:
                printf("eight hundred");
                break;
            case 9:
                printf("nine hundred");
                break;
        }
        int num1;
        num1 = (int)num/100;
        num = num - num1*100;
        if(num > 0){
            printf(" and ");
        }
        switch((int)num/10){
            case 2:
                printf("twenty");
                break;
            case 3:
                printf("thirty");
                break;
            case 4:
                printf("forty");
                break;
            case 5:
                printf("fifty");
                break;
            case 6:
                printf("sixty");
                break;
            case 7:
                printf("seventy");
                break;
            case 8:
                printf("eighty");
                break;
            case 9:
                printf("ninety");
                break;
            default:break;
        }
        int num2;
        num2 = (int)num/10;
        num = num - num2*10;
        if(num2 == 1){
            switch(num){
                case 1:
                    printf("eleven");
                    break;
                case 2:
                    printf("twelve");
                    break;
                case 3:
                    printf("thirteen");
                    break;
                case 4:
                    printf("fourteen");
                    break;
                case 5:
                    printf("fifteen");
                    break;
                case 6:
                    printf("sixteen");
                    break;
                case 7:
                    printf("seventeen");
                    break;
                case 8:
                    printf("eighteen");
                    break;
                case 9:
                    printf("nineteen");
                    break;
                default:printf("ten");
            }
        }
        if(num2 > 1 && num != 0){
            printf("-");
        }
        if(num2 != 1){
            switch((int)num){
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
                default:break;
            }
        }
    }
    else{
        switch((int)num/10){
            case 2:
                printf("twenty");
                break;
            case 3:
                printf("thirty");
                break;
            case 4:
                printf("forty");
                break;
            case 5:
                printf("fifty");
                break;
            case 6:
                printf("sixty");
                break;
            case 7:
                printf("seventy");
                break;
            case 8:
                printf("eighty");
                break;
            case 9:
                printf("ninety");
                break;
            default:break;
        }
        int num2;
        num2 = (int)num/10;
        num = num - num2*10;
        if(num2 == 1){
            switch(num){
                case 1:
                    printf("eleven");
                    break;
                case 2:
                    printf("twelve");
                    break;
                case 3:
                    printf("thirteen");
                    break;
                case 4:
                    printf("fourteen");
                    break;
                case 5:
                    printf("fifteen");
                    break;
                case 6:
                    printf("sixteen");
                    break;
                case 7:
                    printf("seventeen");
                    break;
                case 8:
                    printf("eighteen");
                    break;
                case 9:
                    printf("nineteen");
                    break;
                default:printf("ten");
            }
        }
        if(num2 > 1 && num != 0){
            printf("-");
        }
        if(num2 != 1){
            switch((int)num){
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
                default:break;
            }
        }
    }
}
int main()
{
    int num,num1,num2;
    scanf("%d",&num);
    if(num >= 1000){
        num1 = (int)num/1000;
        num2eng(num1);
        printf(" thousand");
        num2 = (int)num - num1*1000;
        if(num2 != 0 && num2 < 100){
            printf(" and ");
            num2eng(num2);
        }
        else{
            printf(" ");
            num2eng(num2);
        }
    }
    else if(num == 0){
        printf("zero");
    }
    else{
        num2eng(num);
    }
    return 0;
}