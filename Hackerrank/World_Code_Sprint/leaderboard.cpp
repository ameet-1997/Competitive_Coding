#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int score[1000000];
int alice[1000000];
int rank_alice[1000000];

int main()
{	
	int binarysearch(int,int,int);
	int n;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		cin>>score[i];
	}

	rank_alice[0] = 1;

	for(int i=1;i<n;++i)
	{
		if(score[i] == score[i-1])
		{
			rank_alice[i] = rank_alice[i-1];
		}
		else
		{
			rank_alice[i] = rank_alice[i-1] + 1;
		}
	}


	int m;
	cin>>m;

	for(int i=0;i<m;++i)
	{
		cin>>alice[i];
	}

	for(int i=0;i<m;++i)
	{
		int temp = binarysearch(alice[i],0,n-1);

		if(score[temp] == alice[i])
		{
			cout<<rank_alice[temp]<<"\n";
		}
		else if(score[temp] > alice[i])
		{
			cout<<rank_alice[temp]+1<<"\n";
		}
		else
		{	
			if(rank_alice[temp] == 1)
			{
				cout<<"1\n";
			}
			else
			{
				cout<<rank_alice[temp]<<"\n";	
			}
			
		}
	}
}


int binarysearch(int check,int i,int j)
{
	int mid = (i+j)/2;

	if(i == j)
	{
		return i;
	}
	if(score[mid] == check)
	{
		return mid;
	}
	if(score[mid] < check)
	{
		return binarysearch(check,i,mid);
	}

	return binarysearch(check,mid+1,j);
} 
