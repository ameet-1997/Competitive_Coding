#include <bits/stdc++.h>

using namespace std;

vector<int> points(4);

points[0] = 1;
points[1] = 6;
points[2] = 0;
points[3] = 1;

vector< pair<int,int> > matches_left;
map<int,string> teams;

int main()
{	
	void print_points(int);
	teams[0] = "Alak";
	teams[1] = "Godav";
	teams[2] = "Mahan";
	teams[3] = "Sindhu";

	matches_left.push_back(make_pair(0,2));
	matches_left.push_back(make_pair(3,2));
	matches_left.push_back(make_pair(1,2));

	print_points(0);
}

void print_points(int index)
{
	if(index == matches_left.size())
	{	
		// Code here
		return;
	}

	cout<<teams[matches_left[index].first]<<" beats "<<teams[matches_left[index].second]<<"\n";
	points[matches_left[index].first]+=3;

	print_points(index+1);

	cout<<teams[matches_left[index].first]<<" beats "<<teams[matches_left[index].second]<<"\n";
	points[matches_left[index].first]+=3;

	print_points(index+1);

	cout<<teams[matches_left[index].first]<<" beats "<<teams[matches_left[index].second]<<"\n";
	points[matches_left[index].first]+=3;

	print_points(index+1);
}


