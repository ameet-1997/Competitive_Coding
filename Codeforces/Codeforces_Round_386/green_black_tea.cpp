#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n,k,a,b;

	cin>>n>>k>>a>>b;

	int tea;

	int more,less;

	if(a >= b)
	{
		tea = 1;
		more = a;
		less = b;
	}
	else
	{
		tea = 2;
		more = b;
		less = a;
	}

	int group;

	if(more%k == 0)
	{
		group = more/k-1;
	}
	else
	{
		group = more/k;
	}

	if(k >= more)
	{
		for(int i=0;i<a;++i)
		{
			cout<<"G";
		}
		for(int i=0;i<b;++i)
		{
			cout<<"B";
		}
		cout<<"\n";
	}
	else if(less < group)
	{
		cout<<"NO\n";
	}
	else if(less > (group+1)*k)
	{
		cout<<"NO\n";
	}
	else
	{	
		int less_group;
		
		less_group = less/group;

		if(less_group > k)
		{
			less_group = k;
		}

		if(tea == 1)
		{
			int green = more;
			int black = less;

			while((green>=k)&&(black>=less_group))
			{
				if(green >= k)
				{
					for(int i=0;i<k;++i)
					{
						cout<<"G";
					}
					green = green-k;
				}
				if(black >= less_group)
				{
					for(int i=0;i<less_group;++i)
					{
						cout<<"B";
					}
					black = black-less_group ;
				}
			}

			if(green > 0)
			{
				while(green > 0)
				{
					cout<<"G";
					green--;
				}
			}
			if(black > 0)
			{
				while(black > 0)
				{
					cout<<"B";
					black--;
				}
			}
		}
		else if(tea == 2)
		{
			int black = more;
			int green = less;

			while((black>=k)&&(green>=less_group))
			{
				if(black >= k)
				{
					for(int i=0;i<k;++i)
					{
						cout<<"B";
					}
					black = black-k;
				}
				if(green >= less_group)
				{
					for(int i=0;i<less_group;++i)
					{
						cout<<"G";
					}
					green = green-less_group ;
				}
			}

			if(black > 0)
			{
				while(black > 0)
				{
					cout<<"B";
					black--;
				}
			}
			if(green > 0)
			{
				while(green > 0)
				{
					cout<<"G";
					green--;
				}
			}
		}


		cout<<"\n";
	}


} 
 
