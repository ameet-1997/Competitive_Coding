#include<stdio.h>

int main()
{
	for(int i=0;i<16;++i)
	{
		printf("And(a=a[%d],b=sel1,out=x%d);\nAnd(a=b[%d],b=sel2,out=y%d);\nAnd(a=c[%d],b=sel3,out=z%d);\nAnd(a=d[%d],b=sel4,out=w%d);\n\nOr(a=x%d,b=y%d,out=xy%d);\nOr(a=xy%d,b=z%d,out=xyz%d);\nOr(a=xyz%d,b=w%d,out=out[%d]);\n",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
	}
}
