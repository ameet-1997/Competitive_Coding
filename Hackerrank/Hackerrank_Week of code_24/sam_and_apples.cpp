#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int s,t;
	int a,b;
	int m,n;

	int apple_answer = 0,orange_answer = 0;

	int temp_apple,temp_orange;


	//scanf("%d%d%d%d%d%d",&s,&t,&a,&b,&m,&n);
	cin>>s>>t>>a>>b>>m>>n;

	for(int i=0;i<m;++i)
	{
		//scanf("%d",&temp_apple);
		cin>>temp_apple;
		if(((a+temp_apple) >=s)&&((a+temp_apple)<=t))
		{
			apple_answer++;
		}
	}

	for(int i=0;i<n;++i)
	{
		//scanf("%d",&temp_orange);
		cin>>temp_orange;
		if(((b+temp_orange) >=s)&&((b+temp_orange)<=t))
		{
			orange_answer++;
		}
	}

	//printf("%d\n%d\n",apple_answer,orange_answer);
	cout<<apple_answer<<"\n"<<orange_answer<<"\n";
} 
