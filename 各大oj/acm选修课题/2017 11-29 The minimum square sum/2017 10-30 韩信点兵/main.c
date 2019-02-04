#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    for(N=10;;N++)
    {
        if(N%11==10&&N%5==1&&N%6==5&&N%7==4)
        {
            printf("%d",N);
            break;
        }
    }
    return 0;
}
