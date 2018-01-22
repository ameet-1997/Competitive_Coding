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

class sell{
public:
	int day;
	int pid;
	int cid;
	int sid;
	int rid;
	int count;

	sell()
	{
		day=0;
		pid=-1;
		cid=-1;
		sid=-1;
		rid=-1;
	}

	bool operator<(const sell& a) const
	{
		if(day != a.day)
		{
			return (day < a.day);
		}
		else
		{
			if(pid != a.pid)
			{
				return (pid < a.pid);
			}
			else
			{
				if(cid != a.cid)
				{
					return (cid < a.cid);
				}
				else
				{
					if(sid != a.sid)
					{
						return (sid < a.sid);
					}
					else
					{
						if(rid != a.rid)
						{
							return (rid < a.rid);
						}
						else
						{
							return true;
						}
					}					
				}				
			}
		}
	}
};

int main()
{
	int queries;
	cin>>queries;

	set< sell > items;

	while(queries--)
	{
		string type;
		string day;
		string product;
		string region;

		cin>>type>>day>>product>>region;

		int day_start = -1, day_end = -1, pid = -1,cid = -1,sid = -1,rid = -1;

		size_t found1 = day.find(".");
		size_t found2 = product.find(".");
		size_t found3 = region.find(".");

		if(found1 != string::npos)
		{	
			string str = day.substr(0,found1);

			// cout<<"STR is : "<<str<<"\n";
			day_start = stoi(str);
			str = day.substr(found1+1);
			day_end = stoi(str);
		}
		else
		{
			day_start = stoi(day);
			day_end = day_start;
		}

		if(found2 != string::npos)
		{
			pid = stoi(product.substr(0,found2));
			cid = stoi(product.substr(found2+1));
		}
		else
		{
			pid = stoi(product);
		}

		if(found3 != string::npos)
		{
			sid = stoi(region.substr(0,found3));
			rid = stoi(region.substr(found3+1));
		}
		else
		{
			sid = stoi(region);
		}

		// cout<<"The values are : "<<day_start<<" : "<<day_end<<" : "<<pid<<" : "<<cid<<" : "<<sid<<" : "<<rid;

		if(type[0] == 'S')
		{
			sell temp;
			temp.day = day_start;
			temp.pid = pid;
			temp.cid = cid;
			temp.sid = sid;
			temp.rid = rid;
			temp.count = queries;

			items.insert(temp);
		}
		else
		{	
			int answer = 0;
			f(i,day_start,day_end+1)
			{
				sell temp1;
				temp1.day = i;
				temp1.pid = pid;
				temp1.cid = cid;
				temp1.sid = sid;
				temp1.rid = rid;
				temp1.count = queries;

				sell temp2;
				temp2.day = i;
				temp2.pid = pid;
				temp2.cid = cid;
				temp2.sid = sid;
				temp2.rid = rid;
				temp2.count = queries;

				if(pid == -1)
				{
					temp1.pid = -1;
					temp2.pid = 10;
					temp1.cid = -1;
					temp2.cid = 4;
				}

				if(cid == -1)
				{
					temp1.cid = -1;
					temp2.cid = 4;
				}

				if(sid == -1)
				{
					temp1.sid = -1;
					temp2.sid = 7;
					temp1.rid = -1;
					temp2.rid = 25;
				}

				if(rid == -1)
				{
					temp1.rid = -1;
					temp2.rid = 25;
				}		

				int index1 = items.lower_bound(temp1) - items.begin();
				int index2 = items.upper_bound(temp2) - items.begin();

				answer += (index2-index1);		
			}

		}
	}
}