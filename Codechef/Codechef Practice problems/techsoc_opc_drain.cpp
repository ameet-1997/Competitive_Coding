#include<stdio.h>


char drain[22][22];                  ///////////////////////////////////////////////////Initialise  the outer loop
int main()
{
	int h,w,a[22][22],mini,minj,min=0,maxi,maxj,max=0;
	char put='a';
	
	scanf("%d%d",&h,&w);
	
	for(int i=1;i<=h;++i)
	{
		for(int j=1;j<=w;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	if((h!=0)&&(w!=0))
	{
		drain[1][1]=put;
	}
	
	for(int i=1;i<=h;++i)
	{
		for(int j=1;j<=w;++j)
		{
			if(a[i-1][j]<a[i][j])
			{
				mini=i-1;
				minj=j;
				min=a[i-1][j];
			}
			
			if((a[i][j-1]<a[i][j])&&(a[i][j-1]<min))
			{
				mini=i;
				minj=j-1;
				min=a[i][j-1];
			}
			
			if((a[i][j+1]<a[i][j])&&(a[i][j+1]<min))
			{
				mini=i;
				minj=j+1;
				min=a[i][j+1];
			}
			
			if((a[i+1][j]<a[i][j])&&(a[i+1][j]<min))
			{
				mini=i+1;
				minj=j;
				min=a[i+1][j];
			}
			
			if(min==0)
			{
				if(a[i-1][j]>a[i][j])
				{
				maxi=i-1;
				maxj=j;
				max=a[i-1][j];
				}
			
				if((a[i][j-1]>a[i][j])&&(a[i][j-1]>max))
				{
				maxi=i;
				maxj=j-1;
				max=a[i][j-1];
				}
			
				if((a[i][j+1]>a[i][j])&&(a[i][j+1]>max))
				{
				maxi=i;
				maxj=j+1;
				max=a[i][j+1];
				}
			
				if((a[i+1][j]>a[i][j])&&(a[i+1][j]>max))
				{
				maxi=i+1;
				maxj=j;
				max=a[i+1][j];
				}
				
				a[maxi][]	
			}
			else
			{
				a[mini][minj]=put;
				min=0;
			}
			
			
		}
	}
	
	
	
}
