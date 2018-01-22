#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char input[500][500];

int main()
{
	int n,m;

	cin>>n>>m;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>input[i][j];
		}
	}

	int coordinate1 = -1,coordinate2 = -1;
	int coordinate_temp_1,coordinate_temp_2;
	int flag = 0;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(input[i][j] == 'X')
			{	
				coordinate_temp_1 = j;
				while((input[i][j] != '.')&&(j<m))
				{
					j++;
				}
				coordinate_temp_2 = j-1;
				while(j<m)
				{
					if(input[i][j] == 'X')
					{
						flag = 1;
						break;
					}
					++j;
				}

				if(flag == 1)
				{
					break;
				}

				if(coordinate1!=-1)
				{
					if((coordinate_temp_1!=coordinate1)||(coordinate_temp_2!=coordinate2))
					{
						flag = 1;
						break;
					}
				}
				else
				{
					coordinate1 = coordinate_temp_1;
					coordinate2 = coordinate_temp_2;
				}


			}
		}

		if(flag == 1)
		{
			break;
		}
	}

	if(flag)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
} 
