
#include<stdio.h>
#include<windows.h>
#include<conio.h>      
#include <stdlib.h>

#define n 20

DWORD WINAPI body(LPVOID lpParameter);                    //����������߳�
DWORD WINAPI direction(LPVOID lpParameter);            //���Ʒ�����߳�
DWORD WINAPI ball(LPVOID lpParameter);                   //���������ɵ��߳�

void gotoxy(int x,int y);                                  //�����ת��������

char a[n][n]={0},dir,num[10000]={0};                        //a[n][n]Ϊ������̨   dirΪ������Ʊ���     num[10000]Ϊ�洢��������
int k=1,l=0,END=0,speed;                              //speed Ϊ�ٶȿ��Ʊ��� endΪ�����ж���������  k��l�洢β������
 


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
	printf("��ӭ����̰���ߵ����磬һ��ʼ��Ļ�����*����̰���ߣ�������\nʹ��wasd�����Ʒ���\nע����֮ǰ�Ȱ����뷨�ص�������Ӣ�����룩\n#Ϊ����Ϸ���õ�ʳ�������ͻ��᳤\nǧ��ע�ⲻ����ͷ������������*�Ķ����������ں��Լ���\n��ʼʱ����һ�����������Ѷ�����ԽСԽ�콨��1000~500\n\n");
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


DWORD WINAPI ball(LPVOID lpParameter)        //����#�� �߳�3 ball �ı���
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





DWORD WINAPI direction(LPVOID lpParameter)   //���Ʒ��� �߳�2 direction�ı���
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




DWORD WINAPI body(LPVOID lpParameter)   //����������߳�h1 body�ı���
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



void gotoxy(int x, int y)                            //�����ת��������
{
    COORD coord = {x, y};  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
