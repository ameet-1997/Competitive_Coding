/*
This program gives the configuration of the pegs and discs in
each move of towers of hanoi

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{
	void hanoi(int,char*,int &,int &,int &);	//Passing the number of disks in the pegs by reference
	int n;	//Stores the number of disks on the pegs
	char a[3];
	char temp;
	int a1,b1,c1;
	int i;	//Loop variable
	long int answer=1;
	
	a[0]='A';
	a[1]='B';
	a[2]='C';
	
	scanf("%d",&n);
	
	a1=n;
	b1=0;
	c1=0;
	
	hanoi(n,a,a1,b1,c1);
	
	for(i=1;i<=n;++i)	//Calculating 2^n-1
	{
		answer=answer*2;
	}
	answer=answer-1;
	
	printf("%ld",answer);
	return 0;
}



void hanoi(int disk,char* a,int &a1,int &b1,int &c1)
{	char b[3],temp;
	
	if(disk==1)	//If disk==1 then depending on source and destination, the number of disks on each peg is altered
	{	if(a[0]=='A')
		{
			a1--;
		}
		else if(a[0]=='B')
		{
			b1--;
		}
		else if(a[0]=='C')
		{
			c1--;
		}
		
		
		
		if(a[2]=='A')
		{
			a1++;
		}
		else if(a[2]=='B')
		{
			b1++;
		}
		else if(a[2]=='C')
		{
			c1++;
		}
		
		
		printf("%c -> %c %d %d %d\n",a[0],a[2],a1,b1,c1);
	}
	
	else
	{	
		b[0]=a[0];	//Storing the intial values of the array
		b[1]=a[1];
		b[2]=a[2];
	
		temp=a[1];	//Swapping to ensure correct pegs gets correct rings
		a[1]=a[2];
		a[2]=temp;
		
		hanoi(disk-1,a,a1,b1,c1);	//Move n-1 disks
		
		a[0]=b[0];
		a[1]=b[1];
		a[2]=b[2];
		
		hanoi(1,a,a1,b1,c1);	//Move 1 disk
		
		temp=a[0];
		a[0]=a[1];
		a[1]=temp;
		
		hanoi(disk-1,a,a1,b1,c1);	//Move n-1 disks again
		
	}
}

