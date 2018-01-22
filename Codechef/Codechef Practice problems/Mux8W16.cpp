#include<stdio.h>

int main()
{
	for(int i=0;i<16;++i)
	{
		printf("And(a=a[%d],b=sel0,out=x%d);\nAnd(a=b[%d],b=sel1,out=y%d);\nAnd(a=c[%d],b=sel2,out=z%d);\nAnd(a=d[%d],b=sel3,out=w%d);\nAnd(a=e[%d],b=sel4,out=p%d);\nAnd(a=f[%d],b=sel5,out=q%d);\nAnd(a=g[%d],b=sel6,out=r%d);\nAnd(a=h[%d],b=sel7,out=s%d);\n\n\nOr(a=x%d,b=y%d,out=xy%d);\nOr(a=xy%d,b=z%d,out=xyz%d);\nOr(a=xyz%d,b=w%d,out=xyzw%d);\nOr(a=xyzw%d,b=p%d,out=xp%d);\nOr(a=xp%d,b=q%d,out=xpq%d);\nOr(a=xpq%d,b=r%d,out=xpqr%d);\nOr(a=xpqr%d,b=s%d,out=out[%d]);\n\n",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
	}
}
