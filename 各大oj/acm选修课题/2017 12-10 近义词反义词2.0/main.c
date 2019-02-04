#include <stdio.h>
#include <stdlib.h>
#define zero 100010
int i,T,num,gen,zi,c,ans,flag;
int fat[zero+100010];
void init()
{
    for(i=0; i<zero+100010; i++)
    {
        fat[i]=i;
    }
}

int findf(int x)
{
    int root=x;
    while(root != fat[root])//先要找到根节点r
    {
        root=fat[root];
    }
    int y=x;
    while(y!=root)
    {
        int fath=fat[y];
        fat[y]=root;
        y=fath;
    }
    return root;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans=flag=0;
        init();
        scanf("%d",&num);
        for(i=0; i<num; i++)
        {
            scanf("%d%d%d",&gen,&zi,&c);
            gen=gen+zero;
            zi=zi+zero;
            fat[gen]=findf(gen);
            fat[zi]=findf(zi);
            if(fat[gen]!=fat[zi]&&fat[gen]!=2*zero-fat[zi])            //如果不同根则合并
            {
                if(c==0)
                {
                    fat[fat[zi]]=fat[fat[gen]];
                    fat[2*zero-fat[zi]]=fat[2*zero-fat[gen]];
                }
                else if(c==1)
                {
                    fat[fat[zi]]=2*zero-fat[fat[gen]];
                    fat[2*zero-fat[zi]]=fat[fat[gen]];
                }
            }
            else               //同根判断
            {
                if(c==1&&fat[zi]!=2*zero-fat[gen])
                {
                    ans=i;
                    i++;
                    flag=1;
                    break;
                }
                else if(c==0&&fat[zi]!=fat[gen])
                {
                    ans=i;
                    i++;
                    flag=1;
                    break;
                }
            }
            // printf("%d %d\n",fat[zero+1],fat[zero-3]);
        }

        for(; i<num; i++)    scanf("%d%d%d",&gen,&zi,&c); //继续读数据

        if(flag==1) printf("%d\n",ans+1);
        else printf("PERFECT!\n");
    }
    return 0;
}
