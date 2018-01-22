#include<stdio.h>

struct node{
	int a;
	node *next;
}*head,*temp;

int main()
{
	printf("How many nodes do you want to add : ");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		temp=new node;
		if(i==0)
		{
			head=temp;
			temp->next=NULL;
		}
		else
		{
			temp->next=head->next;
			head=temp;
		}
	}
}
