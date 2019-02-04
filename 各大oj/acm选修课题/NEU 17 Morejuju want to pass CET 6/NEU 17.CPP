#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dic
{
	int num;
	char word[100];
	char mean[100];
	struct dic *next;
};
	
int main()
{
	int n,zu,i;
	struct dic *head = NULL;
	struct dic *youxu = NULL;
	struct dic *prev,*current;
	struct dic *maxbefore,*max,*tail,*tem,*p;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&zu);
		for(i=0;i<zu;i++)
		{			
			current=(struct dic*)malloc(sizeof(struct dic));        //stu后年的*是什么意思
			if(head == NULL)
			{
				head=current;
				//current->next=NULL;
			}
			else
			{
				prev->next = current;
				current->next = NULL;
			}

			current->num=i+1;
			scanf("%s%s",current->word,current->mean);

			prev = current;
		}

		while(head!=NULL)
		{
			for(p = head, max = head ; p->next != NULL; p = p->next)
			{
				if(strcmp((p->next->word),max->word)>0)
				{
					maxbefore=p;
					max=p->next;
				}
			}
			if (youxu==NULL)
			{
				youxu=max;
				tail=max;
			}
			else 
			{
				tail->next = max;
				tail = max;
			}
			if(head==max)
				head=head->next;
			else maxbefore->next=max->next;
		}
		if (youxu!= NULL)
			tail->next = NULL;
		for(p=youxu;p!=NULL;p=p->next)
			printf("NO.%d: %s\n",p->num,p->mean);
		for(;youxu!=NULL;)
		{
			if(youxu->next!=NULL)
			{
				tem=youxu->next;
				free(youxu);
				youxu=tem;
			}
			else youxu=youxu->next;
		}
		for(;head!=NULL;)
		{
			if(head->next!=NULL)
			{
				tem=head->next;
				free(head);
				head=tem;
			}
			else head=head->next;
		}

	}
	return 0;
}
