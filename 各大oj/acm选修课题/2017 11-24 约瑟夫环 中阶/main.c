#include <stdio.h>
#include <stdlib.h>
int a[400000000];              //a[i]位第i次出局的人在他那次约瑟夫环的编号
int main()
{
    int n,m,k,i,last;          //last为最后存活的人的编号

    while(scanf("%d%d%d",&n,&m,&k)!=EOF)    //n为总人数 m为喊到该数字就出局 k为开始喊号的人的编号
    {
        last=0;
        k=k-1;
        for(i=0; i<n-1; i++)                   //以下操作均以0为第一项操作 列入有三人则三人编号为 0 1 2
        {
            a[i]=(k+(m-1)%(n-i))%(n-i);         //a[i]为第i个出局的人在队伍里的编号
            k=a[i];                             //k为下一次开始时第一个喊号人的编号（此时因为去除了之前一次的人的编号所以k从原来的a[i]+1变为a[i]）
        }
        for(i=n-2; i>-1; i--)                   //从头复原过程 显然最后只留一人（last）编号为0 倒数第二次假如出局的为0号那么这个0号一定是别人，所以他一定挡在last前面挡刀所以last加一，再算第三次同理假如a[i]即为第i个加上去的人的序号（帮其他人挡刀）
        {
            if(a[i]<=last) last++;
        }

        printf("%d\n",last%(n-1)+1);
    }
    return 0;
}
