#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	scanf("%d",&a);
	for(int i=0;i<m;i++)
	scanf("%d %d",&b,&c);
	
	n=n-k;
	n++;
	n = n*(n-1);
	n=n/2;
	n=n-m;
	cout<<n<<endl;
	return 0;
} 
