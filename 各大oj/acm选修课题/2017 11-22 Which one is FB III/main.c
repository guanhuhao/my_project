#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[11000],i,M,tem1,tem2,k,flagz,flagl,j;

    while(scanf("%d",&M)!=EOF)     //�����жϲ�������
    {
        k=-1;
        flagl=flagz=1;             //��ʼ������

        for(j=0;j<M;j++)
        {
            scanf("%d%d",&tem1,&tem2);   //�����жϲ���
            if(flagz==0||flagz==0) continue;
            if(tem1==1) a[++k]=tem2;      //����һ

            else if(tem1==2)                 //������
            {
                if(k==0)
                {
                    a[k]=inf;
                    k--;
                }
                else if(tem2==a[0]&&tem2!=a[k])
                {
                    flagz=0;
                    for(i=0;i<k;i++) a[i]=a[i+1];
                    a[k--]=inf;
                }
                else if(a[k]==tem2&&tem2!=a[0])
                {
                    flagl=0;
                    a[k--]=inf;
                }
            }
        }
        if(flagz==1&&flagl==0) printf("Stack\n");
        else if(flagl==1&&flagz==0) printf("Queue\n");
        else printf("Not Sure\n");
    }
    return 0;

}
