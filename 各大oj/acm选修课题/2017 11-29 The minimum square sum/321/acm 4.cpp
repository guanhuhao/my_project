#include<stdio.h>
int main()
{
	int N;
	char S[3],tem;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
	{
		gets(S);
		for(int k=0;k<3;k++)
		{
			for(int j=0;j<3;j++)
			{
				if(S[k]<S[j])
				{
					tem=S[k];
					S[k]=S[j];
					S[j]=tem;
				}
			}
		}
	    printf("%c %c %c\n",S[0],S[1],S[2]);
	}
    return 0;
}


