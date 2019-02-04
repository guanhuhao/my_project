#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int * father;
    int * lChild;
    int * rChild;
    int value,deep;
} tree;
int maketree(tree a,int date)
{

}
int main()
{
    tree node;
    int a[10],num,i,date;
    scanf("%d",&num);
    for(i=0;i<num;i++){
            scanf("%d",date);
        maketree(node,date);
    }
    return 0;
}
