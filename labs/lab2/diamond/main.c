#include <stdio.h>

int main()
{
    int  i, j, space;
    //upper rectangle
    space = 4;
    for (j = 1; j <= 5; j++)
    {
        for (i = 1; i <= space; i++)
            printf(" ");
        space--;
        for (i = 1; i <= 2 * j - 1; i++)
            printf("*");
        printf("\n");
     }
     //lower rectangle
     space = 1;
     for (j = 1; j <= 4; j++)
     {
         for (i = 1; i <= space; i++)
             printf(" ");
         space++;
         for (i = 1 ; i <= 2 *(5 - j)-  1; i++)
             printf("*");
         printf("\n");
      }
      return 0;
}
