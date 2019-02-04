#include <stdio.h>
#include <stdlib.h>
int N,T,i,gen,zi,c,flag,ans,j,tem;
int fat[100010],guanxi[100010];  //1为反义词 0为同义词 -1为未标记
int init()
{
    for(i=0; i<=N; i++)
    {
        fat[i]=i;
        //printf("%d\n",N);
        guanxi[i]=-1;
    }
    return 0;
}

int findf(int x)
{
    if(fat[x]==x) return x;
    else return findf(fat[x]);
}

int main()
{
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&N);
            //printf("%d",N);
            init();
            //printf("%d  %d  \n",fat[1],fat[3]);
            flag=0;

            for(i=0; i<N; i++)
            {
                scanf("%d%d%d",&gen,&zi,&c);//guanxi[zi]=c==0?guanxi[gen]:(guanxi[gen]==0?1:0);
                if(flag!=1)
                {
                    if(guanxi[gen]==-1&&guanxi[zi]==-1)
                    {
                        //printf("hahah\n");
                        guanxi[gen]=0;
                        guanxi[zi]=c==0?guanxi[gen]:(guanxi[gen]==0?1:0);
                        fat[zi]=gen;
                    }
                    else if(guanxi[gen]==-1&&guanxi[zi]!=-1)
                    {
                        guanxi[gen]=c==0?guanxi[zi]:(guanxi[zi]==0?1:0);
                        fat[gen]=findf(zi);
                    }
                    else if(guanxi[gen]!=-1&&guanxi[zi]==-1)
                    {
                        guanxi[zi]=c==0?guanxi[gen]:(guanxi[gen]==0?1:0);
                        fat[zi]=findf(gen);
                    }
                    else if (fat[gen]!=fat[zi])
                    {
                        fat[zi]=fat[gen];
                        if((guanxi[gen]+guanxi[zi]+c)%2==1)
                            fat[zi]=-fat[gen]-1;
                    }
                    else if(fat[gen]==fat[zi]&&(guanxi[gen]+guanxi[zi])%2!=c)
                    {
                        flag=1;
                        ans=i;
                    }
                    else if(fat[gen]==-fat[zi]-1&&(guanxi[gen]+guanxi[zi])%2==c)
                    {
                        flag=1;
                        ans=i;
                    }
                }
            }
            printf("%d  %d\n",fat[1],fat[4]);
            if(flag==1) printf("%d\n",ans+1);
            else printf("PERFECT!\n");
        }
    }

    return 0;
}
