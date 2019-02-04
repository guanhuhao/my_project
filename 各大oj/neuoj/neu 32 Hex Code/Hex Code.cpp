#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000],c[10000];
	char judge;
	int i;
	while(gets(a)!=NULL)
	{
		int b[10000];
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]<58&&a[i]>47)
				b[i]=a[i]-48;
			else if(a[i]<71&&a[i>64])
				b[i]=a[i]-65+10;
		}
		for(i=0;i<strlen(a);i=i+2)
		{
			c[i/2]=b[i]*16+b[i+1];
		}

		for(i=0;i<strlen(a)/2;i++)
			printf("%c",c[i]);
		printf("\n");
		
	}
	return 0;
}