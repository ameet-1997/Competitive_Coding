#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand (time(NULL));

	cout<<"10\n";
	for(int zz = 0;zz<10;++zz)
	{
		int n = rand()%10000+1;

		cout<<n<<"\n";

		for(int i=0;i<n;++i)
		{
			cout<<rand()%100000<<" ";
		}
		cout<<"\n";
	}
} 
