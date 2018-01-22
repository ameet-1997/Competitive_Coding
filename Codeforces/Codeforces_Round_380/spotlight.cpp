#include <iostream>

using namespace std;

int a[1000][1000];

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
		}
	}

	//Input received

	int good_number = 0;

	for(int i=0;i<n;++i)
	{
		int first_1 = -1,last_1 = -1,total = 0;

		for(int j=0;j<m;++j)
		{
			if(a[i][j] == 1)
			{
				first_1 = j;
				break;
			}
		}


		for(int j=0;j<m;++j)
		{
			if(a[i][j] == 1)
			{	
				last_1 = j;
				total++;
			}
		}

		if(first_1 != -1)
		{
				//good_number = good_number + first_1 + m -1- last_1 + 2*(last_1 - first_1 -1 -(total-2));
				good_number = good_number - first_1 + last_1 + 1 + m -2*total;
		}
	}


	//Horizontal done

	//cout<<good_number<<"\n";


	for(int i=0;i<m;++i)
	{
		int first_1 = -1,last_1 = -1,total = 0;

		for(int j=0;j<n;++j)
		{
			if(a[j][i] == 1)
			{
				first_1 = j;
				break;
			}
		}


		for(int j=0;j<n;++j)
		{
			if(a[j][i] == 1)
			{	
				last_1 = j;
				total++;
			}
		}

		if(first_1 != -1)
		{
				//good_number = good_number + first_1 + n -1- last_1 + 2*(last_1 - first_1 -1 -(total-2));
				good_number = good_number - first_1 + last_1 + 1 + n -2*total;
		}
	}


	cout<<good_number<<"\n";
} 
