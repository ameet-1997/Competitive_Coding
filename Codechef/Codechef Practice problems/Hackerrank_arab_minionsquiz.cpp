#include<stdio.h>

int main(){

    long int a,b,i=0,number,remainder,quotient,a1,b1;//a is the number of or operators and b is the number of and operators

    int *binary,result;

	binary=new int[(a+b+1)*64];
	
	for(long int k=0;k<a+b+1;++k)
	{
    	printf("Enter the number: ");

    	scanf("%ld",&quotient);

    	while(quotient!=0)
		{

         	binary[k*64+i]=quotient%2;

         	quotient=quotient/2;
         	i++;

    	}
    	for(int j=i;j<64;++j)
    	{
    		binary[k*64+j]=0;
		}
    	i=0;
	}
	a1=a;b1=b;
	for(long int j=0;j<64;++j)
	{	result=binary[0][j];
		
		for(long int k=0;k<a+b;++k)
		{
			if((result==0)&&(next==0))
			{
				break;
			}
		}
	}

}
