/*User friendly version
#include<stdio.h>

int main()
{
	int test,n,sum=0,count=0,prev=0,next=0;
	printf("Enter the number of test cases : ");
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		printf("\nEnter the number of elements in the array : ");
		scanf("%d",&n);
		printf("\nEnter the elements in order : ");
		scanf("%d",&prev);
		next=prev;
		for(int k=1;k<n;++k)
		{	prev=next;
			scanf("%d",&next);
			if(next>=prev)
			{
				count++;	
			}	
			else
			{
				sum=sum+((count)*(count+1))/2;
				count=0;
			}
		}
		sum=sum+((count)*(count+1))/2+n;
		count=0;
		printf("\nThe answer is : %d",sum);
		sum=0;
	}
		
	}
*/

#include<stdio.h>

int main()
{
	int test,n,sum=0,count=0,prev=0,next=0;
	//printf("Enter the number of test cases : ");
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
	//	printf("\nEnter the number of elements in the array : ");
		scanf("%d",&n);
	//	printf("\nEnter the elements in order : ");
		scanf("%d",&prev);
		next=prev;
		for(int k=1;k<n;++k)
		{	prev=next;
			scanf("%d",&next);
			if(next>=prev)
			{
				count++;	
			}	
			else
			{
				sum=sum+((count)*(count+1))/2;
				count=0;
			}
		}
		sum=sum+((count)*(count+1))/2+n;
		count=0;
		printf("\n%d",sum);
		sum=0;
	}
		
}


