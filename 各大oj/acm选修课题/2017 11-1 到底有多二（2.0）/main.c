#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[60]={0}; //story 50 num
    int i,lens,geshu;
    float flag1,flag2,rate;
    while(scanf("%s",a)!=EOF)
    {
        flag1=1;
        flag2=1;
        geshu=0;
        for(lens=0;a[lens]!=0;lens++);

        for(i=0;i<lens;i++)                 //��¼2�ĸ���
        {
            if(a[i]=='2') geshu++;
        }

        if((a[lens-1]-48)%2==0) flag1=2;      //�ж�ż��

        if(a[0]=='-')                            //������Чλ�� �Լ��ж��Ƿ�Ϊ��
        {
            flag2=1.5;
            lens--;
        }

        rate=((float)geshu/lens)*flag1*flag2*100;          //����ٷֱ�
        printf("%.2f%%\n",rate);
        memset(a,0,sizeof(a));

    }
    return 0;
}
