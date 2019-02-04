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
    memset(vis,0,sizeof(vis));             //��ʼ��������ı�� 0Ϊδ���� 1λ����
    for(i=0;i<N;i++) sumren[i]=ren[S];            //Ϊ��Ԯ������������ֵ����һ������������
    for(i=0;i<N;i++)                            //����ʼλ�õ�������� ������
    {
        if(i==S) continue;
        sumlen[i]=len[S][i];
        sumren[i]=ren[i]+sumren[S];
        lujin[i][1]=i;
    }

    vis[S]=1;                                 //��ǳ�ʼ���ѹ�

    for(i=0;i<N;i++)                          //ѭ����ʼ�ƽ�������С����
    {
        tem=INF;
        for(j=0;j<N;j++)                        //Ѱ�������δ�������ĵ�
        {
            if(tem>sumlen[j]&&vis[j]!=1)
            {
                tem=sumlen[j];
                v=j;
            }
        }

        vis[v]=1;      //��Ǹõ��Ѿ���

        for(k=0;k<N;k++)   //���ɲ���
        {
            if(vis[k]==1) continue;
            if(sumlen[k]==sumlen[v]+len[v][k])   //�ܳ���ͬ�ȽϾ�Ԯ������
            {
               // printf("%d  %d  %d\n",sumlen[k],sumlen[v],len[v][k]);
                if(sumren[k]<sumren[v]+ren[k])
                {

                    sumren[k]=sumren[v]+ren[k];
                    for(x=0;x<1000;x++) lujin[k][x]=lujin[v][x];     //��������

                    for(j=0;lujin[k][j]!=-1;j++);                 //��Ӹó���
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
    while(scanf("%d%d%d%d",&N,&M,&S,&D)!=EOF)      //�����ʼ����
    {
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                len[i][j]=INF;
        for(i=0;i<N;i++) scanf("%d",&ren[i]);    //������о�Ԯ������

        for(i=0;i<M;i++)                           //������м�ͨ������
        {
            scanf("%d%d%d",&tem1,&tem2,&tem3);
            len[tem1][tem2]=len[tem1][tem2]<tem3?len[tem1][tem2]:tem3;
            len[tem2][tem1]=len[tem1][tem2]<tem3?len[tem1][tem2]:tem3;
        }
                           //��ʼ��·��


        for(i=0;i<N;i++) count[i]=1;              //��ʼ������

        for(i=0;i<1000;i++)
            for(j=0;j<1000;j++)
                lujin[i][j]=-1;                  //��ʼ��·��

        for(i=0;i<N;i++) lujin[i][0]=S;          //����·�����



        dij();                              //��������

        printf("%d %d\n",count[D],sumren[D]);          //��ӡ��һ���й���Ϣ

        for(i=0;lujin[D][i]!=-1;i++)                        //��ӡ�ڶ����й���Ϣ
        {
            if(i==0) printf("%d",lujin[D][i]);
            else printf(" %d",lujin[D][i]);
        }
        printf("\n");


    }
    return 0;
}
