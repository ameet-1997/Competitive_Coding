#include <iostream>

using namespace std;

//For only prime case

int hash_table[1000010];
int sieve[1000000];
int count[1000000];

int main()
{	
	void construct_sieve(void);
	void construct_hash_table(void);
	

	int test;
	cin>>test;
	
	construct_sieve();
	

	construct_hash_table();
	
	
	for(int zz=0;zz<test;++zz)
	{
		int n;
		cin>>n;
		
		int flag = 0;
		
		for(int i=0;i<80000;++i)	////Change
		{
			count[i] = 0;
		}
		
		int temp;
		
		int answer = 0;
		
		for(int i=0;i<n;++i)
		{
			cin>>temp;
			
			while(temp > 1)
			{
				if(sieve[temp-1] < 0)
				{
					count[hash_table[temp]]++;
					break;
				}
				else
				{
					//count[sieve[temp-1]-1]++;
					int check = sieve[temp-1];
					int current = 0;
					while((temp > 1)&&(temp%check == 0))
					{
						temp = temp/check;
						current = current + 1;
					}
					
					if(current % 2 != 0)
					{
						count[hash_table[check]]++;
					}
				}
			}
			
			
		}
			
			
			
		for(int i=0;i<80000;++i)
		{	
			if(count[i] == 0)
			{
				continue;
			}
			
			if(count[i] > n/2)
			{
				answer = answer + (n-count[i]);
			}
			else
			{
				answer = answer + count[i];
			}
		}
			
		
		
		cout<<answer<<"\n";
		
	}
}


void construct_sieve()
{
	for(int i=0;i<1000000;++i)
	{
		sieve[i] = -1;
	}
	
	int product = 0;
	
	for(int i=1;i<1000000;++i)
	{
		if(sieve[i] == -1)
		{	
			product = (i+1)*2;
			while(product < 1000001)
			{
				sieve[product-1] = i+1;					//Change this : It now stores the largest prime that divides the number
				product = product + (i+1);
			}
		}
	}
	
	return;
}


void construct_hash_table()
{	
	int coun = 0;
	for(int i=1;i<1000000;++i)	
	{
		if(sieve[i] == -1)
		{
			hash_table[i+1] = coun;
			coun++;
		}
	}
	
}

