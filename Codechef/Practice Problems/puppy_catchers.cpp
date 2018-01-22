#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x[1000000];
int y[1000000];
char s[1000000];

int main()
{	
	int binary_searchy(int find,int l,int r);
	int binary_searchx(int find,int l,int r);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>x[i]>>y[i];
	}

	cin>>s;

	sort(x,x+n);
	sort(y,y+n);

	long long answer = 0;
	long long current_answer = 0;

	for(int i=0;i<n;++i)
	{
		if(x[i] >= 0)
		{
			current_answer = current_answer + x[i];
		}
		else
		{
			current_answer = current_answer - x[i];
		}

		if(x[i] >= 0)
		{
			current_answer = current_answer + y[i];
		}
		else
		{
			current_answer = current_answer - y[i];
		}
	}

	answer = current_answer;


	int current_x = 0,current_y = 0;

	for(int i=0;i<m;++i)
	{	
		int index;
		if(s[i] == 'R')
		{	
			current_x = current_x + 1;
			index = binary_searchx(current_x,0,n-1);
			answer = answer + index - n+index; 
		}
		else if(s[i] == 'L')
		{
			index = binary_searchx(current_x,0,n-1);
			current_x = current_x - 1;
			answer = answer -index + n - index;
		}
		else if(s[i] == 'U')
		{	
			current_y = current_y + 1;
			index = binary_searchy(current_y,0,n-1);
			answer = answer + index - n+index; 
		}
		else if(s[i] == 'D')
		{
			index = binary_searchy(current_y,0,n-1);
			current_y = current_y - 1;
			answer = answer -index + n - index;
		}
	}

	answer = answer - current_answer;

	cout<<answer<<"\n";

} 



int binary_searchx(int find,int l,int r)
{
	int mid = (l+r)/2;

	if(l == r)
	{
		return l;
	}
	else
	{
		if(x[mid] < find)
		{
			binary_searchx(find,mid+1,r);
		}
		else
		{
			binary_searchx(find,l,mid);
		}
	}
}


int binary_searchy(int find,int l,int r)
{
	int mid = (l+r)/2;

	if(l == r)
	{
		return l;
	}
	else
	{
		if(y[mid] < find)
		{
			binary_searchx(find,mid+1,r);
		}
		else
		{
			binary_searchx(find,l,mid);
		}
	}
}