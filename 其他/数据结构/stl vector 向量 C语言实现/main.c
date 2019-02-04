#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#define _define_size 3
typedef int Rank;
typedef struct
{
    Rank _elem;
    int _capacity;
    int * _vector;
} vector;

void init(vector *a)
{

    (*a)._elem=0;
    (*a)._capacity=_define_size;
    if(NULL == ((*a)._vector=(int *)malloc(sizeof(int)*_define_size))) {
        printf("������ʼ��ʧ��\n");
        Sleep(10000);
        exit(1);
    }
}

int _size(vector a)
{
    return a._elem;
}
int copy(int * target,int * base,int start,int end)
{
    int i;
    for(i=0;i<end-start;i++) *(target+i)=*(base+start+i);
    return 0;
}
int expend(vector * a)
{
    int * p;
    if((*a)._elem<(*a)._capacity) return 0;
    p=(*a)._vector;
    (*a)._vector=(int *)malloc(sizeof(int) * (*a)._capacity * 2);
    copy((*a)._vector,p,0,(*a)._capacity);
    (*a)._capacity = (*a)._capacity * 2;
    free(p);
    return 1;
}

int push(vector * a,int date)
{
    expend(a);
    *((*a)._vector+(*a)._elem++)=date;
    return 0;
}

int _delete(vector * a,int target)
{
    int i;
    for(i=target-1;i<(*a)._elem-1;i++) *((*a)._vector+i)=*((*a)._vector+i+1);
    (*a)._elem--;
    return 0;
}

int main()
{
    vector my;
    init(&my);
    int op,tem,i;
    printf("������Ҫ���������ͣ�1�����룩 2��ɾ���� 3������� 0���˳���\n");
    scanf("%d",&op);
    while(op)
    {
        if(op==1){
            printf("������Ҫ��������ݣ�\n");
            scanf("%d",&tem);
            if(!push(&my,tem)) printf("����ɹ�\n\n");
        }
        if(op==2){
            printf("��Ҫɾ�����ǵڼ���Ԫ�أ�\n");
            scanf("%d",&tem);
            _delete(&my,tem-1);
        }
        if(op==3){
            printf("�����������Ϊ��\n");
            for(i=0;i<my._elem;i++) printf("%d  ",*(my._vector+i));
            printf("\n\n");
        }
        printf("������Ҫ���������ͣ�1�����룩 2��ɾ���� 3������� 0���˳���\n");
        scanf("%d",&op);
    }
    return 0;
}
//init size  copy expend push pop
