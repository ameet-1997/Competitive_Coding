#include <bits/stdc++.h>
#include <vector>

using namespace std;

//Tested:
//One extra if statement becuase of query in case of l==r i.e., if the query asks to find the sum between 1 and 1

vector<int> input(1000000);
vector<int> segment_tree(3000000);

int main()
{	
	void build_segment_tree(int l,int r,int position);
	void update_segment_tree(int position,int value,int,int,int);
	int get_result_segment_tree(int l,int r,int current_l,int current_r,int);

	int n;
	cin>>n;		//Size of the input array

	fill(segment_tree.begin(),segment_tree.begin()+3*n,0);

	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}

	build_segment_tree(0,n-1,0);

	//Input "1" represents update command and input "2" represents query command
	//Update command is to be followed by two integers, first the position to be changed and the second, the number it is to be changed to
	//Query command is to be follwed by two integers that represent left and right side of the range to which an output is supplied

	int number_of_commands;
	cin>>number_of_commands;

	while(number_of_commands--)
	{
		int choice;
		cin>>choice;

		if(choice == 1)
		{	
			int position,value;
			cin>>position>>value;
			update_segment_tree(position,value,0,n-1,0);
		}
		else if(choice == 2)
		{
			int l,r;
			cin>>l>>r;

			cout<<get_result_segment_tree(l,r,0,n-1,0)<<"\n";
		}
	}

} 


void build_segment_tree(int l,int r,int position)
{	
	if(l == r)
	{
		segment_tree[position] = input[l];
		return;
	}
	else if(l > r)
	{
		return;
	}
	else
	{
		build_segment_tree(l,(l+r)/2,2*position+1);
		build_segment_tree((l+r)/2+1,r,2*position+2);

		segment_tree[position] = segment_tree[2*position+1] + segment_tree[2*position + 2];		
	}

}


void update_segment_tree(int position,int value,int l,int r,int current_position)
{
	if(l == r)
	{
		segment_tree[current_position] = segment_tree[current_position] - input[position] + value;
		input[position] = value;
		return;
	}
	else if(l > r)
	{
		return;
	}
	else
	{
		if(position <= (l+r)/2)
		{	
			segment_tree[current_position] = segment_tree[current_position] - input[position] + value;
			update_segment_tree(position,value,l,(l+r)/2,2*current_position+1);
			return;
		}
		else
		{	
			segment_tree[current_position] = segment_tree[current_position] - input[position] + value;
			update_segment_tree(position,value,(l+r)/2+1,r,2*current_position+2);
			return;	
		}
	}
}


int get_result_segment_tree(int l,int r,int current_l,int current_r,int position)
{

	if(l == r)
	{
		return input[l];
	}
	if(current_l == current_r)
	{
		if((l >= current_l)&&(current_l <= r))
		{
			return segment_tree[current_l];
		}
		else
		{
			return 0;
		}
	}
	else if( current_l > current_r)
	{
		return 0;
	}
	else
	{
		if((current_l >= l)&&(current_r <= r))
		{
			return segment_tree[position];
		}
		else if(( current_l > r)||(current_r < l))
		{
			return 0;
		}
		else
		{
			return get_result_segment_tree(l,r,current_l,(current_l+current_r)/2,2*position+1) + get_result_segment_tree(l,r,(current_l+current_r)/2+1,current_r,2*position+2);
		}
	}
}