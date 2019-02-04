#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	char a[33],b[33],tema[32],temb[32];
	int num1[33],num2[33],i,j,lena,lenb;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",a,b);
		num1[0]=num2[0]=0;
		lena=lenb=0;
		for(i=1;i<33;i++)
		{
			num1[i]='\0';
		    num2[i]='\0';
		}
		if(a[0]=='-')
		{
			for(i=0;i<32;i++)
			{
				num1[i+1]=a[i+1]-48;
				tema[i]=a[i+1];
			}
			lena=strlen(a)-1;
		}
		else 
		{
			for(i=0;i<32;i++)
			{
				num1[i+1]=a[i]-48;
				tema[i]=a[i];
			}
			lena=strlen(a);
		}


		if(b[0]=='-')
		{
			for(i=0;i<32;i++)
			{
				num2[i+1]=b[i+1]-48;
				temb[i]=b[i+1];
			}
			lenb=strlen(b)-1;
		}
		else 
		{
			for(i=0;i<32;i++)	
			{
				num2[i+1]=b[i]-48;
				temb[i]=b[i];
			}
			lenb=strlen(b);
		}

				
		
		if( ( a[0] == '-' && b[0] == '-' ) || (a[0] != '-'&&b[0] != '-'))
		{
			if( (lena > lenb) || ( lena==lenb && strcmp(tema,temb) > 0 ))
			{
				for(i=lena,j=lenb;i>0&&j>0;i--,j--)
				{
					num1[i]=num1[i]-num2[j];
					if(num1[i]<0)
					{
						num1[i]=num1[i]+10;
						num1[i-1]--;
					}

				}
				for(i=lena;i>0;i--)
				{
					if(num1[i]<0 && i!=1)
					{
						num1[i-1]--;
						num1[i]+=10;
					}
				}
				for(i=1;num1[i]==0;i++);
				for(;i<lena+1;i++)
					printf("%d",num1[i]);
				printf("\n");


			}
			else if((lena < lenb) || (lena==lenb && strcmp(tema,temb)<0))
			{
				for(i=lenb,j=lena;i>0&&j>0;i--,j--)
				{
					num2[i]=num2[i]-num1[j];
					if(num2[i]<0)
					{
						num2[i]=num2[i]+10;
						num2[i-1]--;
					}
				}
				for(i=lenb;i>0;i--)
				{
					if(num2[i]<0)
					{
						num2[i-1]--;
						num2[i]+=10	;
					}
				}
				for(i=1;num2[i]==0;i++);
				for(;i<lenb+1;i++)
					printf("%d",num2[i]);
				printf("\n");
			}
			else printf("0\n");
		}
		
		else
		{
			if(lena>=lenb)
			{
				for(i=lena,j=lenb;i>-1 && j>-1;i--,j--)
				{
					num1[i]=num1[i]+num2[j];
					if(num1[i]>9)
					{
						num1[i]-=10;
						num1[i-1]+=1;
					}
				}
				for(i=lena;i>0;i--)
				{
					if(num1[i]>9)
					{
						num1[i]-=10;
						num1[i-1]+=1;
					}
				}
				for(i=0;num1[i]==0;i++);
				for(;i<lena+1;i++)
					printf("%d",num1[i]);
				printf("\n");
				
			}
			else
			{
                for(i=lenb,j=lena;i>-1 && j>-1;i--,j--)
				{
					num2[i]=num2[i]+num1[j];
					if(num2[i]>9)
					{
						num2[i]-=10;
						num2[i-1]+=1;
					}
				}
				for(i=lenb;i>0;i--)
				{
					if(num2[i]>9)
					{
						num2[i]-=10;
						num2[i-1]+=1;
					}
				}
				for(i=0;num2[i]==0;i++);
				for(;i<lenb+1;i++)
					printf("%d",num2[i]);
				printf("\n");
				

			}
		
		}

	}
	return 0;
}