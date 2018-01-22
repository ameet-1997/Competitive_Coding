#include <iostream>

using namespace std; 


long long int a[100010];

int main()
{
	int n,int p;
	int input[100000];


	cin>>n>>p;

	//less than p, not less than or equal to

	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}

	a[0] = input[0];


	for(int i=1;i<n;++i)
	{
		a[i] = a[i-1] + input[i];
	}


}
