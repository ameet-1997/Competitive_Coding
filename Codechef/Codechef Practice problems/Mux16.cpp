#include<stdio.h>

int main()
{
	int i=0;
	for(i=0;i<16;++i)
	{
		printf("Mux(a=a[%d],b=b[%d],sel=sel,out=out[%d]);\n",i,i,i);
	}
}
