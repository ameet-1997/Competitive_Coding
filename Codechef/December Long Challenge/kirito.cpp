#include <iostream>
#include <time.h>
#define replace 10000000

using namespace std;

int a[replace];
int prime_hash[replace];	//represents the index at which that prime number is stored


int main()
{	
	void construct_sieve(void);
	void build_hash(void);
	int test;

	cin>>test;

	int path[670000];

	int input[100000];
	int stack[100000];
	int stack_pointer = 0;

	//const clock_t begin_time = clock();

	construct_sieve();
	build_hash();

	//const clock_t end_time = clock();

	//cout<<float(end_time-begin_time) / CLOCKS_PER_SEC;

	for(int zz=0;zz<test;++zz)
	{
		int n;
		cin>>n;

		for(int i=0;i<n;++i)
		{
			cin>>input[i];
		}

		for(int i=0;i<670000;++i)
		{
			path[i] = 0;
		}

		for(int i=n-1;i>=0;--i)
		{	
			if(input[i] == 1)
			{
				continue;
			}
			if(a[input[i]-1] == 0)
			{
				path[prime_hash[input[i]]]++;
			}
			else
			{	
				int check_max = 0;
				while((input[i]!=1)&&(a[input[i]-1] != 0))
				{
					int temp = a[input[i]-1];

					while(input[i]%temp == 0)
					{
						input[i] = input[i]/temp;
					}

					stack[stack_pointer] = temp;
					stack_pointer++;

					if(path[prime_hash[temp]] > check_max)
					{
						check_max = path[prime_hash[temp]];
					}

					//path[prime_hash[temp]]++;
				}
				if((input[i]!=1)&&(stack[stack_pointer-1] != input[i]))
				{	
					if(path[prime_hash[input[i]]] > check_max)
					{
						check_max = path[prime_hash[input[i]]];
					}
					stack[stack_pointer] = input[i];
					stack_pointer++;
				}

				while(stack_pointer > 0)
				{
					path[prime_hash[stack[stack_pointer-1]]] = check_max + 1; 
					stack_pointer--;
				}
			}
		}

		int max = 0;

		for(int i=0;i<670000;++i)
		{	
			if(path[i] > max)
			{
				max = path[i];
			}
		}	

		if(max == 0)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<max<<"\n";	
		}
			
	}
} 

void construct_sieve()
{
	for(long long int i=2;i<=3200;++i)
	{	
		if(a[i-1] > 0)
		{
			continue;	//If not prime, then no need to evaluate
		}

		long long int check = 2;
		long long int temp = check*i;

		while(temp <= replace)
		{	
			if(a[temp-1] == 0)
			{
				a[temp-1] = i;	//Will store the smallest prime divisor of the number
			}
			check++;
			//temp = temp+check;
			temp = check*i;
		}
	}
}

void build_hash(void)
{	
	int count = 0;
	for(int i=1;i<=replace;++i)
	{
		if(a[i] == 0)
		{
			prime_hash[i+1] = count;
			count++;
		}
	}
}