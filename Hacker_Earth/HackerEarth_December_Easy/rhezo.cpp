#include <iostream>
#include <string.h>

using namespace std;


int a[10000];

int main()
{
	char s[10000];

	char c;
	int p;
	

	cin>>s>>c>>p;

	int len = strlen(s);

	if(s[0] == c)
	{
		a[0] = 1;
	}

	for(int i=1;s[i]!='\0';++i)
	{
		if(s[i] == c)
		{
			a[i] = a[i-1] + 1;
		}
		else
		{
			a[i] = a[i-1];
		}
	}



	int max=0;
	int max_index;

	for(int i=len-1;i>=p-1;--i)
	{
		int check = a[i] - a[i-p+1];
		if(s[i-p+1] == c)
		{
			check++;
		}

		if(check > max)
		{
			max = check;
			//max_index = i;
		}
	}

	for(int i=len-1;i>=p-1;--i)
	{
		int check = a[i] - a[i-p+1];
		if(s[i-p+1] == c)
		{
			check++;
		}

		if((check == max)&&(s[i-p+1] != c))
		{
			cout<<i+1<<"\n";
			return 0;
		}		
	}

	cout<<"-1"<<"\n";




} 
