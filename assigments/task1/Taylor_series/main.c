#include <stdio.h>
#include <stdlib.h>

int main()
{

    int exponent,iteration_number,i;
    int fact = 1;
    float sum=1.0;

    printf("please enter the exponent and the number of iteration\n");
    scanf("%d%d",&exponent,&iteration_number);
    float item=exponent;

    for(i=1;i<iteration_number;i++)
    {
        fact = fact*i;
        sum = sum + (item/fact);
        item = item*exponent;

    }

    printf("result %f",sum);

    return 0;
}
