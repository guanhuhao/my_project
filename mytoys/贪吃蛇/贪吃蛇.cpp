
#include<stdio.h>
#include<windows.h>
#include<conio.h>      
#include <stdlib.h>

#define n 20

DWORD WINAPI body(LPVOID lpParameter);                    //控制身体的线程
DWORD WINAPI direction(LPVOID lpParameter);            //控制方向的线程
DWORD WINAPI ball(LPVOID lpParameter);                   //控制球生成的线程

void gotoxy(int x,int y);                                  //光标跳转函数本体

char a[n][n]={0},dir,num[10000]={0};                        //a[n][n]为整个舞台   dir为方向控制变量     num[10000]为存储动作数组
int k=1,l=0,END=0,speed;                              //speed 为速度控制变量 end为程序判定结束变量  k和l存储尾部动作
 


int main()
{
	int i,j;
	char RESTART=0;
	loop:
	for(i=0;i<n;i++)
	{
		a[n-1][i]='*';
		a[0][i]='*';
		a[i][n-1]='*';
		a[i][0]='*';
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%c ",a[i][j]);
		printf("\n");
	}
	printf("欢迎来到贪吃蛇的世界，一开始屏幕中央的*就是贪吃蛇（！？）\n使用wasd来控制方向\n注意玩之前先把输入法关掉（调成英文输入）\n#为本游戏设置的食物碰到就会变♂长\n千万注意不能让头碰到碰到所有*的东西（包括壁和自己）\n开始时输入一个数字来调难度数字越小越快建议1000~500\n\n");
	scanf("%d",&speed);
	HANDLE h1,h2,h3;
	h1 = ::CreateThread(NULL, 0, body, NULL, 0, NULL);
	h2 = ::CreateThread(NULL, 0, direction, NULL, 0, NULL);
	h3 = ::CreateThread(NULL, 0, ball, NULL, 0, NULL);



	while(1)
	{
		gotoxy(0,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			printf("%c ",a[i][j]);
			printf("\n");
		}
		Sleep(2);
		if(END==1)
			break;
	}

	if(END==1)
	{
		system("CLS");
		printf("\n\n\n\n\n\n\n\n                          GAME OVER\n\n\n\n\n\n\n");
	}




	return 0;
}


DWORD WINAPI ball(LPVOID lpParameter)        //控制#球 线程3 ball 的本体
{
	int c1=6,c2=7;
	a[c1][c2]='#';
	while(1)
	{
		if(a[c1][c2]=='#')
			continue;
		else
		{
			
			while(1)
			{
				c1=rand()%(n-2)+1;
				c2=rand()%(n-2)+1;
				if(a[c1][c2]!='*')
					break;
			}
			a[c1][c2]='#';
		}
		Sleep(speed);
		if(END==1)
			break;
	}
	return 0;
   


}





DWORD WINAPI direction(LPVOID lpParameter)   //控制方向 线程2 direction的本体
{
	dir='w';
	char t=0;
	while(1)
	{
		t=getch();
		if(t!='w' && t!='a' && t!='s' && t!='d')
			continue;
		if(dir=='w'&&t=='s')
			continue;
		if(dir=='s'&&t=='w')
			continue;
		if(dir=='d'&&t=='a')
			continue;
		if(dir=='a'&&t=='d')
			continue;

		else dir=t;
		if(END==1)
			break;
	}
	return 0;


}




DWORD WINAPI body(LPVOID lpParameter)   //控制身体的线程h1 body的本体
{
	int RL=5,UD=5;
    int b1=UD,b2=RL;
	while(1)
	{   
		if(dir=='w')
		{
			UD--;
			num[k]='w';
			k++;
		}

	    else if(dir=='s')
		{	
			UD++;
			num[k]='s';
			k++;
		}
		else if(dir=='a')
		{
			RL--;
			num[k]='a';
			k++;
		}
		else if(dir=='d')
		{
			RL++;
			num[k]='d';
			k++;
		}
		if(a[UD][RL]=='*')
		{
			END = 1;
			break;
		}
		if(a[UD][RL]=='#')
			a[UD][RL]='*';
		else
		{
			a[b1][b2]=' ';
			a[UD][RL]='*';                              
			if(num[l]=='w')
				b1--;
			if(num[l]=='s')
				b1++;
			if(num[l]=='a')
				b2--;
			if(num[l]=='d')
				b2++;
			l++;


		}

		Sleep(speed);


	}
	END=1;
	return 0;

}



void gotoxy(int x, int y)                            //光标跳转函数本体
{
    COORD coord = {x, y};  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
