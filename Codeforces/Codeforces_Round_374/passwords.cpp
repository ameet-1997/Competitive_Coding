#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int n,k;

	int a[10000];

	char s[10000];
	int answer;

	cin>>n>>k;

	for(int i=0;i<n;++i)
	{
		cin>>s;

		a[i] = strlen(s);

	}

	cin>>s;
	answer = strlen(s);

	sort(a,a+n);

	int i;
	int j;

	for(i = 0;i<n;++i)
	{
		if(a[i] == answer)
		{
			break;
		}
	}

	for(j = n-1;j>=0;--j)
	{
		if(a[j] == answer)
		{
			break;
		}
	}

	int best_case = i+1 + (i/k)*5;
	int worst_case = j +1+ (j/k)*5;

	cout<<best_case<<" "<<worst_case<<"\n";
} 
