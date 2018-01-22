#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;

		for(int j=0;j<n;++j)
		{
			int temp;

			cin>>temp;

			switch(temp%8)
			{
				case 1:{
					cout<<(temp/8)*8+4<<"LB\n";
					break;	
				} 

				case 2:{
					cout<<(temp/8)*8+5<<"MB\n";
					break;
				}

				case 3:{
					cout<<(temp/8)*8+6<<"UB\n";
					break;
				}
				case 4:{
					cout<<(temp/8)*8+1<<"LB\n";
					break;
				}
				case 5:{
					cout<<(temp/8)*8+2<<"MB\n";
					break;
				}

				case 6:{
					cout<<(temp/8)*8+3<<"UB\n";
					break;
				}

				case 7:{
					cout<<(temp/8)*8+8<<"SU\n";
					break;
				}
				case 0:{
					cout<<temp-1<<"SL\n";
					break;
				}

			}
		}
	}

