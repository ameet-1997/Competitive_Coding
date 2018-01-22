#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	char s[1000];
	char str[1000];

	cin>>s;

	/*int count = 0;

	for(int i=0;s[i]!='\0';++i)
	{
		str[count] = s[i];
		count++;

	}

	for(int i=0;s[i]!='\0';++i)
	{
		str[count+i] = s[i];
		count++;
	}

	str[count] = '\0';*/


	char check[1000];
	//char till_now[1000];
	check[0] = s[0];
	check[1] = '\0';


	for(int i=1;s[i]!='\0';++i)
	{
		int j=0;
		int other = i;
		int flag = 0;
		while((check[j]!='\0')&&(s[other]!='\0'))
		{
			if(check[j] != s[other])
			{
				flag = 1;
				break;
			}
			j++;
			other++;
		}


		if(flag == 1)
		{	int jj=0;
			for(jj=0;jj<=i;++jj)
			{
				check[jj] = s[jj];
			}
			check[jj] = '\0';
		}
		else
		{
			i = other-1;
		}

	}

	if(strlen(check) == strlen(s))
	{
		cout<<strlen(s)<<"\n";
	}
	else if(strlen(s)%strlen(check) == 0)
	{
		cout<<strlen(check)<<"\n";
	}
	else
	{
		cout<<strlen(s)<<"\n";
	}

} 
