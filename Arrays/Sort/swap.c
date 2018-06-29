#include<stdio.h>
void main()
{
  int a=5,b=7;
  printf("a=%d, b=%d",a,b);
  a=a+b;
  b=a-b;
  a=a-b;
  printf("a=%d, b=%d",a,b);
}
