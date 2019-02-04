#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void fun()
{
    extern x,y;
    int a=5,b=10;
    x=a-b;
    y=a+b;
}
int x,y,main()
{
    int a=7,b=5;
    return 0;
}
