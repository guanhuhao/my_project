#include <stdio.h>
#include <stdlib.h>
int binary_search(int *a,int target,int len,int flag);
int main()
{
    int a[]= {0,1,2,3,4,5,6,7,8,9};
    int target;
    printf("��Ҫ���ҵ���Ϊ��\n");

    while(~scanf("%d",&target))
        binary_search(a,target,sizeof(a)/sizeof(int),1);
    return 0;
}
int binary_search(int a[],int target,int len,int flag)         //1Ϊ���� 0Ϊ����
{
    int head,tail,mid;
    head=0;
    tail=len-1;
    mid=(head+tail)/2;
    //printf("%d  %d\n",*(a+head),*(a+tail));
    if(target>=*(a+head)&&target<=*(a+tail))
    {
        do
        {
            printf("%d\n",mid);
            if(*(a+mid)==target)
            {
                printf("�����ҵ���λ��ԭ�����%dλ\n",mid+1);
                return 0;
            }
            else if(*(a+mid)>target)
            {
                tail=flag==1?mid:tail;
                head=flag==1?head:mid;
            }
            else
            {
                tail=flag==1?tail:mid;
                head=flag==1?mid:head;
            }
            mid=(head+tail)/2;
        }
        while(head<tail);
    }
    printf("δ�ҵ�Ŀ��Ԫ��\n");
    return 0;
}
