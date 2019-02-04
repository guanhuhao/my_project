#include <stdio.h>
int main()
{
	int nian,yue,ri,mon[12]={31,28,31,30,31,30,31,31,30,31,30,31},day,i;
	char a;
	while(scanf("%d%c%d%c%d",&nian,&a,&yue,&a,&ri) != EOF)
	{
      for(day=0,i=0;i<yue-1;i++)  day=day+mon[i];
      day=day+ri;
      if(yue>2 && (nian%400 == 0 || ( nian%4==0 && nian%100!=0))) day++;
      printf("%d\n",day);
	}
	return 0;
}
