#include<conio.h>                  //getch()
#include<windows.h>
#include<stdio.h>
#include <stdlib.h>



#define Row 8
#define Col 12

DWORD WINAPI ball(LPVOID lpParameter);               //���̺߳������壨����
DWORD WINAPI bar(LPVOID lpParameter); 

char a[Row][Col]={0};                                  //ȫ�ֱ���
int RL=1,UD=1;

void gotoxy(int x,int y);                              //�����ת��������

int main()
{                            
	int i,j;
	char any;
	for(i=0;i<Row-1;i++)                         //����к���
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
	
	for(i=0;i<Row;i++)                   //������
		{
			printf("\n");
		    for(j=0;j<Col;j++)
			    printf(" %c |",a[i][j]);
		}

	printf("\n��Ϸ����\n1����*������С��������_�����϶��Լ��������߻ᷴ�����µײ��ᣩ��\n 2����asdw����ʹС���ƶ�\n��С��������_����ô��_���ͻ���ʧ���������ݵ��Ǹ�����ֻҪ����ƶ��¾��ֻ�����ˡ�������\n�ر��������Ȱ����뷨���˲�Ȼ��������\n\n\n\n�����������ʼ��Ϸ\n");
    any=getch();
	
	HANDLE h1,h2;
	h1 = ::CreateThread(NULL, 0, ball, NULL, 0, NULL);         //�߳�һ

	h2 = ::CreateThread(NULL, 0, bar, NULL, 0, NULL);          //�̶߳�
	
	
	
	
	while(1)
	{
	    gotoxy(0,0);
		for(i=0;i<Row;i++)                   //������
		{
			printf("\n");
		    for(j=0;j<Col;j++)
			    printf(" %c |",a[i][j]);
		}
		 Sleep(2);
	}
	return 0;




}








DWORD WINAPI ball(LPVOID lpParameter)                     //�߳�һ��������
{
	for(int i=3,j=5;1==1;i=i+UD,j=j+RL)
	{
		if(i==Row)
		break;
		a[i-UD][j-RL]=0;
		if(a[i][j]=='_'||i==1)                             //����if�жϱ߽練�� 
			UD=-UD;
		if(j==Col-1||j==1)
			RL=-RL;
		a[i][j]='*';
		
		Sleep(500);

	}
    return 0;
}


DWORD WINAPI bar(LPVOID lpParameter)                     //�̶߳�
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












void gotoxy(int x, int y)                            //�����ת��������
{
    COORD coord = {x, y};  

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}