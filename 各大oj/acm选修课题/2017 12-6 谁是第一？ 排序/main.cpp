#include <iostream>
#include <stdio.h>
using namespace std;
struct student
{
    char name[20];
    int score;
}stu[100];

bool Cmpare(const student &sco, const student &stu)            //const����ӣ���Ȼ���Ŀǰ����Ϊɶ����return����tureʱ��a�����������ʾ����������
{
     return stu.score < stu.a;
}

int main()
{
    int T,num,i;
    while(scanf("%d",&T)!=EOF)
    {
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            scanf("%s%d",stu[i].name,&stu[i].score);
        }
        sort(stu,stu+num,cmp)
    }
    return 0;

}
