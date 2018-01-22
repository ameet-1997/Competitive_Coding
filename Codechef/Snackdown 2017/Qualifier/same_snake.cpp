#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int x11, y11, x12, y12;
		int x21, y21, x22, y22;

		cin>>x11>>y11>>x12>>y12;
		cin>>x21>>y21>>x22>>y22;

		bool col1 = false, row1 = false, col2 = false, row2 = false;

		if(x11 == x12)
		{
			col1 = true;
		}

		if(y11 == y12)
		{
			row1 = true;
		}

		if(x21 == x22)
		{
			col2 = true;
		}

		if(y21 == y22)
		{
			row2 = true;
		}

		bool result = false;

		if(col1 && col2)
		{
			if(x11 == x21)
			{
				if(((max(y11,y12) >= min(y21, y22))&&(min(y11,y12) <= min(y21, y22)))||((max(y21,y22) >= min(y11, y12))&&(min(y21,y22) <= min(y11, y12))))
				{
					result = true;
				}
			}
		}

		if(row1 && row2)
		{
			if(y11 == y21)
			{
				if(((max(x11,x12) >= min(x21, x22))&&(min(x11,x12) <= min(x21, x22)))||((max(x21,x22) >= min(x11, x12))&&(min(x21,x22) <= min(x11, x12))))
				{
					result = true;
				}
			}
		}

		if(col1 && row2)
		{
			if(((x11 == x21)&&(y11 == y21))||((x11 == x22)&&(y11 == y22))||((x11 == x21)&&(y12 == y21))||((x11 == x22)&&(y12 == y22)))
			{
				result = true;
			}
		}

		if(row1 && col2)
		{
			if(((x21 == x11)&&(y21 == y11))||((x21 == x12)&&(y21 == y12))||((x21 == x11)&&(y22 == y11))||((x21 == x12)&&(y22 == y12)))
			{
				result = true;
			}
		}

		if(result)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
}