#include <iostream>

using namespace std;

int main()
{
	int n;

	cin>>n;

	char s[10000];

	cin>>s;

	int counter = 0;
	int a[10000];


	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i] == 'B')
		{	
			int temp = i;
			while((s[i] == 'B')&&(s[i]!='\0'))
			{
				i++;
			}

			a[counter] = i-temp;
			counter++;
		}
	}

	cout<<counter<<"\n";

	for(int i=0;i<counter;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";

} 
