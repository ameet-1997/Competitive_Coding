#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 

int main()
{
	int n;
	cin>>n;

	vi A(1000001);
	vi B(1000001);
	// vi mark(1000000);

	fill(A.begin(), A.end(), 0);
	fill(B.begin(), B.end(), 0);

	rep(i,n)
	{
		int temp;
		cin>>temp;

		A[temp-1]++;
	}

	rep(i,n)
	{
		int temp;
		cin>>temp;

		B[temp-1]++;
	}


	// rep(i,10)
	// {
	// 	cout<<A[i]<<" ";
	// }
	// cout<<"\n";

	// rep(i,10)
	// {
	// 	cout<<B[i]<<" ";
	// }
	// cout<<"\n";

	int answer = 0;

	for(int d=1;d<=1000000;++d)
	{	
		int flag1 = false, flag2 = false;
		for(int l=1;l<=1000000/d;++l)
		{
			if(A[l*d-1])
			{
				flag1=true;
			}

			if(B[l*d-1])
			{
				flag2 = true;
			}
		}

		if(flag1&&flag2)
		{
			answer = max(answer, d);
		}
	}

	int num1=0, num2 = 0;

	rep(i,1000001)
	{
		if(A[i])
		{
			if((i+1)%answer == 0)
			{
				num1 = i+1;
			}
		}
	}

	rep(i,1000001)
	{
		if(B[i])
		{
			if((i+1)%answer == 0)
			{
				num2 = i+1;
			}
		}
	}

	cout<<num1+num2<<"\n";

	// rep(i,n)
	// {
	// 	cin>>A[i];
	// }

	// rep(i,n)
	// {
	// 	cin>>B[i];
	// }

	// sort(A.begin(), A.end());
	// sort(B.begin(), B.end());

	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=1;j*j<=A[i];++j)
	// 	{	
	// 		if(A[i]%j == 0)
	// 		{
	// 			mark[j-1] = 1;
	// 			mark[A[i]/j-1] = 1;				
	// 		}
	// 	}
	// }

	// // rep(i,30)
	// // {
	// // 	cout<<mark[i]<<" ";
	// // }
	// // cout<<"\n";


	// for(int i=0;i<n;++i)
	// {
	// 	for(int j=1;j*j<=B[i];++j)
	// 	{	
	// 		if(B[i]%j == 0)
	// 		{
	// 			if(mark[j-1] >= 1)
	// 			{
	// 				mark[j-1]++;
	// 			}

	// 			if(mark[B[i]/j-1] >= 1)
	// 			{
	// 				mark[B[i]/j-1]++;
	// 			}				
	// 		}
	// 	}
	// }


	// // rep(i,30)
	// // {
	// // 	cout<<mark[i]<<" ";
	// // }
	// // cout<<"\n";

	// int answer = 0;

	// rep(i,1000000)
	// {
	// 	if(mark[i] >= 2)
	// 	{
	// 		answer = i+1;
	// 	}
	// }

	// // cout<<"Answer is : "<<answer<<"\n";

	// int num1 = 0, num2 = 0;

	// rep(i,n)
	// {
	// 	if(A[i]%answer == 0)
	// 	{
	// 		num1 = A[i];
	// 	}

	// 	if(B[i]%answer == 0)
	// 	{
	// 		num2 = B[i];
	// 	}
	// }

	// cout<<num1+num2<<"\n";
}
