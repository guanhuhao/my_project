#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int jiaquan[17]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char M[11]= {'1','0','X','9','8','7','6','5','4','3','2'};
    char a[110][18];
    int N=2,i,j,tem,flag,count,k;
    while(scanf("%d",&N)!=EOF)
    {
        memset(a,0,sizeof(a));
        count=0;
        for(i=0; i<N; i++)
        {
            scanf("%s",a[i]);
        }
        for(i=0; i<N; i++)
        {
            tem=0;
            flag=0;                    //初始化

            for(j=0; j<17; j++)
            {
                if(a[i][j]<48||a[i][j]>57)
                {
                                                            //如何打印二维数组中的某一行
                    printf("%s",a[i]);
                    //for(k=0;k<18;k++)  printf("%c",a[i][k]);
                    printf("\n");
                    flag=1;
                    break;
                }
            }                               //判断是否都为数字

            if(flag==1)
            {
                count++;
                continue;
            }

            for(j=0; j<17; j++)               //计算加权
            {
                tem=(a[i][j]-48)*jiaquan[j]+tem;
            }
            tem=tem%11;

            if(a[i][17]!=M[tem])
            {
                printf("%s\n",a[i]);
                //for(k=0;k<18;k++)  printf("%c",a[i][k]);
                printf("\n");
                count++;
            }
        }
        if(count==0) printf("All passed\n");
    }
    return 0;
}
