#include<stdio.h>
int main()
{
 int first_term=0,sec_term=1,third_term,i,no_of_terms;
 printf("number of terms:");
 scanf("%d",&no_of_terms);
 printf("%d,%d",first_term,sec_term);
 for(i=2;i<no_of_terms;i++)
 {
  third_term=first_term+sec_term;
  printf(",%d",third_term);
  first_term=sec_term;
  sec_term=third_term;
 }
  return 0;
 }
