#include <stdio.h>
#include <stdlib.h>
char a[110000];
int main()
{
    int N,n,m,i,L,R;
    scanf("%d",&N);
    while(N--)
    {
        L=R=0;

        scanf("%d%d",&n,&m);
        getchar();
        gets(a);

        for(i=m-1;i>0;i--)
        {
            if(a[i]=='R') L++;
        }

        for(i=m-1;i<n-1;i++)
        {
            if(a[i]=='L') R++;
        }

        printf("%d\n",L<R?L:R);
    }
    return 0;
}
