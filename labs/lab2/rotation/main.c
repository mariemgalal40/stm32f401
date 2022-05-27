#include <stdio.h>
int main()
{
    unsigned char x,bn;
    unsigned int type;
    printf("please enter the number and the number of bits\n");
    scanf("%hhu%hhu", &x , &bn);
    printf("for left enter 1 ,for right enter 2\n");
    scanf("%u",&type);
    if( type==1 ){
    x= (x<< bn )|(x>> (8-bn));
    printf("x=%i\n",x);
    }
    else if (type ==2){
    x=(x>>bn)|(x<<(8-bn));
    printf("x=%i\n",x);
    }
    else{
        printf("error");
    }

    return 0;
}
