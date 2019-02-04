#include<stdio.h>
int main()
{
	char a[10000];
	int i,rank=25,star,win=0;
	gets(a);
	for(i=0;a[i]!=EOF;i++)
	{
		if( a[i]=='W' && win>=2 &&rank>5)
			star=star+2;
		else if( a[i]=='W' ) 
		{
			star++;
			win++;
		}
		else if(a[i]=='L' &&( rank<1 && (rank>20 && star!=0) ) )
		{
			star--;
		}
		else if(a[i]=='L') win=0;

		if(rank>20)
		{
			if(star>2)
			{
				star=star-2;
				rank--;
			}
		}
		else if(rank>15)
		{
			if(star>3)
			{
				rank--;
				star=star-3;
			}
		}
		else if(rank>10)
		{
			if(star>4)
			{
				rank--;
				star=star-4;
			}

		} else if(rank>0)
		{
			if(star>5)
			{
				star=star-5;
				rank--;
			}
		}

		if(star<0 && rank!=0)
			rank++;


	}
	printf("%d",rank);
	return 0;
}