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
        printf("向量初始化失败\n");
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
    printf("输入你要操作的类型：1（插入） 2（删除） 3（输出） 0（退出）\n");
    scanf("%d",&op);
    while(op)
    {
        if(op==1){
            printf("输入你要插入的数据：\n");
            scanf("%d",&tem);
            if(!push(&my,tem)) printf("插入成功\n\n");
        }
        if(op==2){
            printf("你要删除的是第几个元素：\n");
            scanf("%d",&tem);
            _delete(&my,tem-1);
        }
        if(op==3){
            printf("向量里的数据为：\n");
            for(i=0;i<my._elem;i++) printf("%d  ",*(my._vector+i));
            printf("\n\n");
        }
        printf("输入你要操作的类型：1（插入） 2（删除） 3（输出） 0（退出）\n");
        scanf("%d",&op);
    }
    return 0;
}
//init size  copy expend push pop
