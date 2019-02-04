#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[11000][3][10];
long long gcd(long long a,long long b) //求最大公约数
{
    if(a==0)    return b;
    else return gcd(b%a,a);
}

int main()
{
    int N,num,i,j,tem;
    long long ratea,rateb;
    scanf("%d",&N);
    while(N--)
    {
        ratea=1;
        rateb=1;
        scanf("%d",&num);
        getchar();

        for(i=0;i<num;i++)            //输入
        {
            for(j=0;j<3;j++)
                scanf("%s",a[i][j]);
        }

        for(i=0;i<num;i++)               //接下来这段基本都是重复的
        {
            if(strncmp(a[i][0],"UFS2.0",6)==0)
            {
                ratea=ratea*2;
                rateb=rateb*3;
            }
            else if(strncmp(a[i][0],"UFS2.1",6)==0)
            {
                ratea=ratea*3;
                rateb=rateb*5;
            }
            else if(strncmp(a[i][0],"eMMC5.1",7)==0)
            {
                ratea=ratea*5;
                rateb=rateb*2;
            }

            if(strncmp(a[i][1],"LPDDR3",6)==0)
            {
                ratea=ratea*4;
                rateb=rateb*7;
            }
            else if(strncmp(a[i][1],"LPDDR4",6)==0)
            {
                ratea=ratea*6;
                rateb=rateb*3;
            }

            if(strncmp(a[i][2],"Sparse",6)==0)
            {
                ratea=ratea*7;
                rateb=rateb*4;
            }
            if(strncmp(a[i][2],"Normal",6)==0)
            {
                ratea=ratea*3;
                rateb=rateb*6;
            }

            tem=gcd(ratea,rateb);            //以下三步约分
            ratea=ratea/tem;
            rateb=rateb/tem;


        }
        if(ratea>rateb) printf("A  %lld  %lld\n",ratea,rateb);
        if(ratea<rateb) printf("B  %lld  %lld\n",ratea,rateb);
        if(ratea==rateb) printf("E  %lld  %lld\n",ratea,rateb);


    }
    getchar();
    return 0;
}
