#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1000000]={0};       //0λ���ֵ 1Ϊ���� 0Ϊδ������
int main()
{
    int n,m,k,count1,count2,i;       //nΪ��n�˲μ� ����ʱ����m���˳��� kΪ�ӵڼ��˿�ʼ���� count1Ϊ��¼ÿ���˱����� count2Ϊ�м��˳���
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        count2=count1=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        i=k;

        while(count2<n-1)
        {
            count1=count1+1;                  //�൱�ڱ���
            if(count1==m) {a[i]=1;count1=0;count2++;}  //�ж��Ƿ񱨵�ָ������ ��������жϳ��� ����a[i]���Ϊ1��ͬʱ��ͷ��ʼ����count=0��ͬʱ����������1 count2++

            if(i<n) i++;
            else if(i==n) i=1;   //�ж��Ƿ񵽴��β ���򷵻ؿ�ͷ i=1 ��������һ����

            while(a[i]==1)      //�ж���һ�����Ƿ���� ���������һ�� ֱ���ֵ�һ��û���ֵ�ֹͣ
            {
                if(i<n) i++;
                    else if(i==n) i=1;     // printf("%d\n",i);

            }
        }
        for(i=0;a[i]==1;i++);   //Ѱ�ҵ�һ��Ϊ0��Ԫ�� ��Ϊ�������˵����

        printf("%d\n",i); //���
;    }
    return 0;
}
