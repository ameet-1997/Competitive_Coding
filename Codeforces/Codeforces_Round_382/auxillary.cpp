#include <iostream>

using namespace std;

int main()
{
	long long int a[100];
	a[0] = 1;
	a[1] = 3;

	int i=2;
	for(i=2;i<100;++i)
	{
		a[i] = a[i-1] + a[i-2] + 1;

		cout<<"a["<<i<<"] = "<<a[i]<<";\n";
		if(a[i] > 2*1000000000000000000)
		{
			break;
		}
	} 
} 
