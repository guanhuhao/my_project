#include <stdio.h>
#include <stdlib.h>
struct
{
    char name[25];
    int ave_sco;
    int class_sco;
    char cadre;
    char west;
    int thesis;
    int money;
}stu[100];
int main()
{
    int num,i,tem=0,sum=0;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%s%d%d",&stu[i].name,&stu[i].ave_sco,&stu[i].class_sco);
        getchar();
        scanf("%c",&stu[i].cadre);
        getchar();
        scanf("%c",&stu[i].west);
        scanf("%d",&stu[i].thesis);
    }
    for(i=0;i<num;i++)
    {
        stu[i].money=0;
        if(stu[i].ave_sco > 80 && stu[i].thesis>0)  stu[i].money+=8000;
        if(stu[i].class_sco > 80 && stu[i].ave_sco > 85) stu[i].money+=4000;
        if(stu[i].ave_sco > 90 )  stu[i].money+=2000;
        if(stu[i].west=='Y' && stu[i].ave_sco > 85) stu[i].money+=1000;
        if(stu[i].cadre=='Y' && stu[i].class_sco > 80) stu[i].money+=850;
    }
    for(i=0;i<num;i++)
    {
        if(stu[i].money > stu[tem].money) tem=i;
        sum=sum+stu[i].money;
    }
    printf("%s\n%d\n%d",stu[tem].name,stu[tem].money,sum);
    return 0;
}
