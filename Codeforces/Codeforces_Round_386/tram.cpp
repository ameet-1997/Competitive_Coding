#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int s,x1,x2;
	int t1,t2;

	cin>>s>>x1>>x2;
	cin>>t1>>t2;

	int tram_initial,direction;
	cin>>tram_initial>>direction;

	int igor_time = (x2-x1)*t2,tram_time;
	if(igor_time < 0)
	{
		igor_time = -igor_time;
	}

	if(t2 <= t1)
	{
		cout<<igor_time<<"\n";
	}
	else
	{
		if(x2 > x1)
		{	
			if(tram_initial <= x1)
			{
				if(direction > 0)
				{
					tram_time = (x2-tram_initial)*t1;
				}
				else
				{
					tram_time = 2*tram_initial*t1 + (x2-tram_initial)*t1;
				}				
			}
			else if(tram_initial <= x2)
			{	
				if(direction > 0)
				{
					tram_time = 2*s*t1 + (x2-tram_initial)*t1;	
				}
				else
				{
					tram_time = 2*tram_initial*t1 + (x2-tram_initial)*t1;
				}
				
			}
			else
			{
				if(direction > 0)
				{
					tram_time = 2*s*t1 + (x2-tram_initial)*t1;	
				}
				else
				{
					tram_time = (tram_initial+x2)*t1;
				}
			}

		}
		else
		{
			direction = direction*-1;
			x2 = s-x2;
			x1 = s-x1;
			tram_initial = s - tram_initial;


			if(tram_initial <= x1)
			{
				if(direction > 0)
				{
					tram_time = (x2-tram_initial)*t1;
				}
				else
				{
					tram_time = 2*tram_initial*t1 + (x2-tram_initial)*t1;
				}				
			}
			else if(tram_initial <= x2)
			{	
				if(direction > 0)
				{
					tram_time = 2*s*t1 + (x2-tram_initial)*t1;	
				}
				else
				{
					tram_time = 2*tram_initial*t1 + (x2-tram_initial)*t1;
				}
				
			}
			else
			{
				if(direction > 0)
				{
					tram_time = 2*s*t1 + (x2-tram_initial)*t1;	
				}
				else
				{
					tram_time = (tram_initial+x2)*t1;
				}
			}			


		}

		cout<<min(igor_time,tram_time)<<"\n";	
	}
	
} 
