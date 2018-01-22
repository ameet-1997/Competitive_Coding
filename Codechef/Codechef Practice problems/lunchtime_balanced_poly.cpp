#include <iostream>

using namespace std;


struct point{
	int x;
	int y;
	int one;
	int zero;
};

struct color{
	int x;
	int y;
	int cl;
};

int combination[51];

int main()
{
	int test;
	point p[50];
	color c[50];
	
	int combination[51] = {0,2,6,20,70,252,924,3432,12870,48620,184756,705432,2704156,10400600,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	cin>>test;
	
	for(int zz = 0;zz<test;++zz)
	{	
		int zeros = 0,ones = 1;
		int n,m;
		
		cin>>n>>m;	//Input taken
		
		for(int i=0;i<n;++i)
		{
			cin>>p[i].x>>p[i].y;
			p[i].one = p[i].zero = 0;
		}
		
		for(int i=0;i<m;++i)
		{
			cin>>c[i].x>>c[i].y>>c[i].cl;
			
			if(c[i].cl == 0)
					{
					
						zeros++;	
					}
					else
					{
				
						ones++;	
					}
		}
		
		int answer = 0;
		
		int max;
		if(zeros > ones)
		{
			max = ones;
		}
		else
		{
			max = zeros;
		}
		
		answer = answer + combination[max];
		
		answer = answer - 1 -n*n;
		cout<<answer<<"\n";
		
		/*for(int i=0;i<n;++i)
		{
			int z = 0,o = 0;
			
			z = p[i].zero;
			o = p[i].one;
			
			if(i+1 == n)
			{
				z = z + p[0].zero;
				o = o + p[0].one;
			}
			else
			{
				z = z + p[i+1].zero;
				o = o + p[i+1].one;
			}
			
			if(i+2 == n)
			{
				z = z + p[0].zero;
				o = o + p[0].one;
			}
			else if(i+2 == n+1)
			{
				z = z + p[1].zero;
				o = o + p[1].one;
			}
			else
			{
				z = z + p[i+2].zero;
				o = o + p[i+2].one;
			}
			
			if(z == o)
			{
				answer++;
			}
			
			for(int j=0;j<n-3;++j)
			{
				z = z + p[(i+j+3)%n].zero;
				o = o + p[(i+j+3)%n].one;
				
				if(z == o)
				{
					answer++;
				}
			}
		}
		
		int z = 0;
		int o = 0;
		for(int i=0;i<n;++i)
		{
			z = z + p[i].zero;
			o = o + p[i].one;
		}
		
		if(z == o)
		{
			answer = answer - (n-1);
		}
		
		
		
		cout<<answer<<"\n";*/
		
		
	}
}
