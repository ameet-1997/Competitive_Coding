#include<stdio.h>

int main() {
    int test,n,*a,*max,sub=0,non=0;
    scanf("%d",&test);
    for(int i=0;i<test;++i)
        {
        scanf("%d",&n);
        a=new int[n];
        max=new int[n];
        for(int q=0;q<n;++q)
        {
        	scanf("%d",&a[q]);
		}
        max[n-1]=a[n-1];
        for(int j=n-2;j>=0;--j)
            {
         if(max[j+1]<0)
             {
             max[j]=a[j];
         }
            else
                {
                max[j]=a[j]+max[j+1];
            }
        }
        sub=max[0];
        for(int l=0;l<n;++l)
            {
            if(max[l]>sub)
                {
                sub=max[l];
            }
            if(a[l]>0)
                {
                non=non+a[l];
            }
        }
        printf("%d %d\n",sub,non);
        sub=0;non=0;n=0;
    }
    return 0;
}

