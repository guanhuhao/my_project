#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int N,M,S,D,count[1000];
int ren[1000],len[1000][1000],vis[1000];
int sumlen[1000],sumren[1000];
int lujin[1000][1000];

void dij()
{
    int i,j,k,v,tem,x;
    memset(vis,0,sizeof(vis));             //初始化经过点的标记 0为未经过 1位经过
    for(i=0;i<N;i++) sumren[i]=ren[S];            //为救援队总人数赋初值（第一个城市人数）
    for(i=0;i<N;i++)                            //从起始位置到个点距离 及人数
    {
        if(i==S) continue;
        sumlen[i]=len[S][i];
        sumren[i]=ren[i]+sumren[S];
        lujin[i][1]=i;
    }

    vis[S]=1;                                 //标记初始点已过

    for(i=0;i<N;i++)                          //循环开始逼近各点最小距离
    {
        tem=INF;
        for(j=0;j<N;j++)                        //寻找最近且未被经过的点
        {
            if(tem>sumlen[j]&&vis[j]!=1)
            {
                tem=sumlen[j];
                v=j;
            }
        }

        vis[v]=1;      //标记该点已经过

        for(k=0;k<N;k++)   //放松操作
        {
            if(vis[k]==1) continue;
            if(sumlen[k]==sumlen[v]+len[v][k])   //总长相同比较救援队人数
            {
               // printf("%d  %d  %d\n",sumlen[k],sumlen[v],len[v][k]);
                if(sumren[k]<sumren[v]+ren[k])
                {

                    sumren[k]=sumren[v]+ren[k];
                    for(x=0;x<1000;x++) lujin[k][x]=lujin[v][x];     //复制数组

                    for(j=0;lujin[k][j]!=-1;j++);                 //添加该城市
                    lujin[k][j]=k;
                }
                count[k]=count[k]+count[v];
            }
            else if(sumlen[k]>sumlen[v]+len[v][k])
            {

                sumlen[k]=sumlen[v]+len[v][k];
                sumren[k]=sumren[v]+ren[k];
                //printf("%d \n",sumren[k]);
                for(x=0;x<1000;x++) lujin[k][x]=lujin[v][x];
                for(j=0;lujin[k][j]!=-1;j++);
                lujin[k][j]=k;
                count[k]=count[v];
            }
        }

    }

}
int main()
{
    int i,j,tem1,tem2,tem3;
    while(scanf("%d%d%d%d",&N,&M,&S,&D)!=EOF)      //输入初始数据
    {
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                len[i][j]=INF;
        for(i=0;i<N;i++) scanf("%d",&ren[i]);    //输入城市救援队人数

        for(i=0;i<M;i++)                           //输入城市间通道距离
        {
            scanf("%d%d%d",&tem1,&tem2,&tem3);
            len[tem1][tem2]=len[tem1][tem2]<tem3?len[tem1][tem2]:tem3;
            len[tem2][tem1]=len[tem1][tem2]<tem3?len[tem1][tem2]:tem3;
        }
                           //初始化路径


        for(i=0;i<N;i++) count[i]=1;              //初始化个数

        for(i=0;i<1000;i++)
            for(j=0;j<1000;j++)
                lujin[i][j]=-1;                  //初始化路径

        for(i=0;i<N;i++) lujin[i][0]=S;          //设置路径起点



        dij();                              //函数处理

        printf("%d %d\n",count[D],sumren[D]);          //打印第一行有关信息

        for(i=0;lujin[D][i]!=-1;i++)                        //打印第二行有关信息
        {
            if(i==0) printf("%d",lujin[D][i]);
            else printf(" %d",lujin[D][i]);
        }
        printf("\n");


    }
    return 0;
}
