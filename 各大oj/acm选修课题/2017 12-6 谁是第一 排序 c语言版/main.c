#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[20];
    int score;
} stu[105];

int main()
{
    int T,num,i,jilu;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&num);
            for(i=0; i<num; i++)
            {
                scanf("%s%d",stu[i].name,&stu[i].score);
            }
            //for(i=0;i<num;i++) printf("%s\n",stu[i].name);
            jilu=0;
            for(i=1; i<num; i++)
            {
                if(stu[i].score>stu[jilu].score)
                {
                    jilu=i;
                }
                else if(stu[i].score==stu[jilu].score&&strcmp(stu[i].name,stu[jilu].name)<0)
                {
                    jilu=i;
                }
            }
            if(strcmp(stu[jilu].name,"myt")==0) printf("Defense of the Ancients\n");
            else printf("learn from %s\n",stu[jilu].name);
        }
    }
    return 0;

}
