#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double x[110000];
double cmp ( const void *a , const void *b )
{
  return *(double *)a - *(double *)b;
}

int main()
{
    int i,j,k,num,flag;
    double a,b,c,tem,r1,r2,sum,tem2;
    while(scanf("%d",&num)!=EOF)
    {
        sum=0;
        scanf("%lf%lf%lf",&a,&b,&c);
        for(i=0;i<num;i++) scanf("%lf",&x[i]);
        qsort(x,num,sizeof(x[0]),cmp);
        printf("%lf  %lf  %lf\n",x[0],x[1],x[2]);
        i=0;j=1;
        r1=(x[1]-x[0])/2;
        tem=a*r1*r1+b*r1+c;
        while(i<num)
        {
            tem2=c;
            for(;i+j<num;j++)
            {
                r1=(x[j+i]-x[i])/2;printf("%lf    %lf         1\n",x[0],x[1]);
                tem=a*r1*r1+b*r1+c;
                flag=0;
                for(k=0;j-k>0;k++)
                {
                    r1=(x[i+j]-x[i+j-k])/2;
                    r2=(x[i+j-k-1]-x[i])/2; printf("%lf    %lf     %lf\n",a*r1*r1+b*r1+c,a*r2*r2+b*r2+c,tem);
                    if(tem<=a*r1*r1+b*r1+c+a*r2*r2+b*r2+c) break;

                    tem=a*r1*r1+b*r1+c+a*r2*r2+b*r2+c;
                    tem2=a*r2*r2+b*r2+c;
                    flag=1;
                }
                if(flag==1) break;
            }
            printf("%d %d %d  %lf\n",i,j,k,tem2);
            sum=sum+tem2;
            tem=tem-tem2;
            i=i+j-k+1;
            j=k;
                        printf("%d %d %d  %lf\n",i,j,k,tem2);
        }
        sum=sum+a*r1*r1+b*r1+c;
        printf("%.5lf\n",sum);
    }
    return 0;
}
