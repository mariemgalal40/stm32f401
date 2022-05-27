
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float u, a,t;
    printf("please enter initial velocity");
    scanf("%f", &u);
     printf("please enter acceleration");
    scanf("%f", &a);
     printf("please enter time");
    scanf("%f", &t);
    float v = u+(a*t);
    float s = u*t +(.5*a*t*t);
    printf("%f\n",v);
    printf("%f",s);
    return 0;
}


/*

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2,num3;
    printf("enter tree different integers :");
    scanf("%d%d%d", &num1,&num2,&num3);
    int sum = num1+num2+num3;
    float average = sum/3;
    int product = num1*num2*num3 ;
    int largest1= (num1>num2)?num1:num2;
    int largest=(largest1>num3)?largest1:num3;
    int smallest1=(num1<num2) ?num1:num2;
    int smallest=( smallest1<num3)?smallest1:num3;
    printf("sum=%d\n",sum);
    printf("average=%f\n",average);
    printf("product=%d\n",product);
    printf("smallest=%d\n",smallest);
    printf("largest=%d\n",largest);
    //printf("%f",v);
    //printf("%f",s);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{   int seconds;
    printf("please enter seconds");
    scanf("%d",&seconds);
    int hours = seconds /3600;

    int minutes =(seconds%3600)/60;

    int sec = seconds%60;

    printf("%d:%d:%d",hours, minutes, sec);
    return 0;
}

*/
