#include<conio.h>                  //getch()
#include<windows.h>
#include<stdio.h>
#include <stdlib.h>



#define Row 8
#define Col 12

DWORD WINAPI ball(LPVOID lpParameter);               //多线程函数定义（？）
DWORD WINAPI bar(LPVOID lpParameter); 

char a[Row][Col]={0};                                  //全局变量
int RL=1,UD=1;

void gotoxy(int x,int y);                              //光标跳转函数定义

int main()
{                            
	int i,j;
	char any;
	for(i=0;i<Row-1;i++)                         //输出行和列
		a[i+1][0]='A'+i;
	for(i=0;i<Col-1;i++)
		a[0][i+1]=49+i;
    for(i=1;i<Col;i++)
	{
		a[1][i]='_';
	    a[2][i]='_';
		a[3][i]='_';
		a[4][i]='_';
	}
	a[3][5]='*';
	a[Row-1][Col/2]='_';
	
	for(i=0;i<Row;i++)                   //输出表格
		{
			printf("\n");
		    for(j=0;j<Col;j++)
			    printf(" %c |",a[i][j]);
		}

	printf("\n游戏规则：\n1、“*”代表小球，碰到“_”或上顶以及左右两边会反弹（下底不会）。\n 2、摁asdw可以使小棒移动\n（小球碰到“_”那么“_”就会消失，包括操纵的那个，但只要随便移动下就又会出现了。。。）\n特别提醒下先把输入法关了不然操作不了\n\n\n\n输入任意键开始游戏\n");
    any=getch();
	
	HANDLE h1,h2;
	h1 = ::CreateThread(NULL, 0, ball, NULL, 0, NULL);         //线程一

	h2 = ::CreateThread(NULL, 0, bar, NULL, 0, NULL);          //线程二
	
	
	
	
	while(1)
	{
	    gotoxy(0,0);
		for(i=0;i<Row;i++)                   //输出表格
		{
			printf("\n");
		    for(j=0;j<Col;j++)
			    printf(" %c |",a[i][j]);
		}
		 Sleep(2);
	}
	return 0;




}








DWORD WINAPI ball(LPVOID lpParameter)                     //线程一函数本体
{
	for(int i=3,j=5;1==1;i=i+UD,j=j+RL)
	{
		if(i==Row)
		break;
		a[i-UD][j-RL]=0;
		if(a[i][j]=='_'||i==1)                             //两组if判断边界反弹 
			UD=-UD;
		if(j==Col-1||j==1)
			RL=-RL;
		a[i][j]='*';
		
		Sleep(500);

	}
    return 0;
}


DWORD WINAPI bar(LPVOID lpParameter)                     //线程二
{
	char c;
	int j=Col/2,i=Row-1;
	a[i][j]='_';
	for(;;)
	{
		c=getch();
		if(c=='a'&&j>1)
		{
				j--;
				a[i][j]='_';
				a[i][j+1]=0;
		}
		if(c=='d'&&j<Col-1)
		{
			j++;
			a[i][j]='_';
		    a[i][j-1]=0;
		}
	    if(c=='w'&&i>5)
		{
			i--;
			a[i][j]='_';
		    a[i+1][j]=0;
		}
	    if(c=='s'&&i<Row-1)
		{
			i++;
			a[i][j]='_';
		    a[i-1][j]=0;
		}
	}
}












void gotoxy(int x, int y)                            //光标跳转函数本体
{
    COORD coord = {x, y};  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}