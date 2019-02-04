#include<stdio.h>
int main()
{
	int current,after,turn;
    scanf("%d%d",&current,&after);
	turn=after-current;
	if(turn>180) turn=-(360-turn);
	if(turn<-180) turn=(360+turn);
	if(turn==-180) turn=180;
	printf("%d\n",turn);
}