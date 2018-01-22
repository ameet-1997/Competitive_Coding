#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int a[5]; //A,T,G,C,?

int main()
{
	int n;

	cin>>n;
	char s[1000];
	cin>>s;
	char printing[1000];

	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i] == 'A')
		{
			a[0]++;
		}
		else if(s[i] == 'T')
		{
			a[1]++;
		}
		else if(s[i] == 'G')
		{
			a[2]++;
		}
		else if(s[i] == 'C')
		{
			a[3]++;
		}
		else
		{
			a[4]++;
		}
	}

	int total = n;
	char ins[5];
	ins[0] = 'A';
	ins[1] = 'T';
	ins[2] = 'G';
	ins[3] = 'C';


	
	if((total%4 != 0)||(a[0] > total/4)||(a[1] > total/4)||(a[2] > total/4)||(a[3] > total/4))
	{
		cout<<"===\n";
	}
	else
	{
		int index = 0;

		for(int i=0;i<4;++i)
		{
			for(int j=0;j<(total/4-a[i]);++j)
			{
				printing[index] = ins[i];
				index++;
			}
		}
		printing[index] = '\0';
		index = 0;
		for(int i=0;s[i]!='\0';++i)
		{
			if(s[i] == '?')
			{
				s[i] = printing[index];
				index++;
			}
		}

		cout<<s<<"\n";
	}
}
