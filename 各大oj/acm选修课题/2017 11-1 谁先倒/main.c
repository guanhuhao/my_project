#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jia,yi,N,jiahe,yihe,jiahua,jiahan,yihan,yihua,sum,i;
    while(scanf("%d%d",&jia,&yi)!=EOF)
    {
        jiahe=yihe=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d%d%d%d",&jiahan,&jiahua,&yihan,&yihua);
            sum=jiahan+yihan;
            if(jiahua==sum&&yihua!=sum) jiahe++;
            if(jiahua!=sum&&yihua==sum) yihe++;
            if(jiahe>jia||yihe>yi) break;
        }
        for(i++;i<N;i++) scanf("%d%d%d%d",&jiahan,&jiahua,&yihan,&yihua);
        if(jia<jiahe) printf("A\n%d\n",yihe);
        else printf("B\n%d\n",jiahe);


    }
    return 0;
}
