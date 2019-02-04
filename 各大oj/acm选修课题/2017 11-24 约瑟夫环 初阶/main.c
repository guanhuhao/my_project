#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1000000]={0};       //0位标记值 1为出局 0为未被出局
int main()
{
    int n,m,k,count1,count2,i;       //n为有n人参加 报数时报到m的人出局 k为从第几人开始报数 count1为计录每个人报的数 count2为有几人出局
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        count2=count1=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        i=k;

        while(count2<n-1)
        {
            count1=count1+1;                  //相当于报数
            if(count1==m) {a[i]=1;count1=0;count2++;}  //判断是否报到指定数字 如果是则判断出局 所以a[i]标记为1，同时从头开始报数count=0，同时出局人数加1 count2++

            if(i<n) i++;
            else if(i==n) i=1;   //判断是否到达队尾 是则返回开头 i=1 不是则下一个人

            while(a[i]==1)      //判断下一个人是否出局 是则继续下一个 直到轮到一个没出局的停止
            {
                if(i<n) i++;
                    else if(i==n) i=1;     // printf("%d\n",i);

            }
        }
        for(i=0;a[i]==1;i++);   //寻找第一个为0的元素 则为最后存活的人的序号

        printf("%d\n",i); //输出
;    }
    return 0;
}
