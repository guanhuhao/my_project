#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100000][3]={0};
int main()
{
	int zu=0,num,i,j,k;  //zu����������� num�������� a��ά����Ϊ�˵ĸ������ b��������ֵ  i j kΪѭ������
	clock_t start,end;
	scanf("%d",&zu);
	while(zu--)
	{
		int b[100000]={0};
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			for(j=0;j<3;j++)
			a[i][j]=rand()%100+1;    //scanf("%d",&a[i][j]);
		}
	    start=clock();
		for(i=0;i<num;i++)
		{
			for(j=1;j<num;j++)
			{
				if(a[i][0]<a[j][0])
				{
					if(a[i][1]<a[j][1]&&a[i][2]<a[i][2])
					{
					    b[j]+=1;
					    continue;
					}
				}
				else if(a[i][1]<a[j][1])
				{
				    if(a[i][2]<a[i][2]&&a[][])
					{
					    b[j]+=1;
					    continue;
					}
				}
				if(a[i][2]<a[j][2])
				{
				    b[j]+=1;
				    continue;
				}
		         b[i]+=1;
			}
		}
		for(i=0;i<num;i++)
			printf("%d\n",b[i]);
		end=clock();
		printf("����ʱ��Ϊ��%d",end-start);
	}
				
	    
	return 0;
}
