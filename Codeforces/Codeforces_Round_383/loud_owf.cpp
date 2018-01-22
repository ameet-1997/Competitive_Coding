#include <iostream>

using namespace std;

int cycles[1000];
int count = 0;
int a[1000];
int checked[1000];
int cycle_length = 0;

int main()
{	
	int gcd(int,int);
	int dfs(int,int);
	int n;
	cin>>n;

	for(int i=1;i<=n;++i)
	{
		cin>>a[i];	//One based indexing
	}

	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}

	for(int i=1;i<=n;++i)
	{
		if(checked[i] == 0)
		{	
			cycle_length = 0;
			int temp = dfs(i,i);

			//cout<<"Temp is : "<<temp<<"\n";

			if(temp == -1)
			{
				cout<<"-1\n";
				return 0;
			}
		}
	}

	//cout<<count<<"\n";

	if(count == 1)
	{
		if(n%2 == 0)
		{
			cout<<n/2<<"\n";
		}
		else
		{
			cout<<n<<"\n";
		}
	}
	else if(count == n)		//If all self loops
	{
		cout<<"1\n";
	}
	else
	{
		long long lowest_common_multiple = 1;
		//lowest_common_multiple = cycles[0]*cycles[1]/gcd(cycles[0],cycles[1]);

		for(int i=0;i<count;++i)
		{	
			if(cycles[i]%2 == 0)
			{
				lowest_common_multiple = lowest_common_multiple*(cycles[i]/2)/gcd(lowest_common_multiple,cycles[i]/2);	
			}
			else
			{
				lowest_common_multiple = lowest_common_multiple*cycles[i]/gcd(lowest_common_multiple,cycles[i]);
			}
			
		}

		cout<<lowest_common_multiple<<"\n";
	}

} 


int dfs(int i,int parent)
{	
	//cout<<"I is : "<<i<<"  a[i] is : "<<a[i]<<"\n";
	if(checked[i]!=0)
	{
		if(parent == i)
		{
			cycles[count] = cycle_length;
			count++;
			return parent;
		}
		else
		{
			return -1;
		}
	}

	checked[i] = 1;

	cycle_length++;
	return dfs(a[i],parent);

}


int gcd(int c,int b)
{
	if(b>c)
	{
		return gcd(b,c);
	}
	if(c%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b,c%b);
	}
}
