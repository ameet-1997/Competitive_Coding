#include<stdio.h>
#include<math.h>
int main()
{
	char* a,temp;
	int test,bits,letters;
	printf("Enter the number of test cases : ");
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		printf("\nEnter the number of bits in the string : ");
		scanf("%d",&bits);
		letters=pow(2,bits);
		a=new char[letters];
		printf("\nEnter the phrase : ");
		scanf("%s",a);
		for(int j=0;j<=(letters-1)/2;j++)
		{
			temp=a[j];
			a[j]=a[letters-1-j];
			a[letters-1-j]=temp;
		}
		printf("\nThe scrambled message is : ");
		printf("\n%s",a);
		delete[] a;
	}
}
