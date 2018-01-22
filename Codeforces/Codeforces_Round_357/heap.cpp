// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// int n;
// multiset<int> ss;

// char buf[100];

// vector<pair<char, int> > vv;

// int main() {
// 	scanf("%d", &n);
// 	for (int i = 0; i < n; ++i) {
// 		scanf(" %s", buf);
// 		int x;
// 		if (buf[0] == 'i') {
// 			scanf("%d", &x);
// 			ss.insert(x);
// 			vv.push_back(make_pair('i', x));
// 		}
// 		else if (buf[0] == 'g') {
// 			scanf("%d", &x);
// 			while (!ss.empty() && *ss.begin() < x)
// 				vv.push_back(make_pair('r', 0)), ss.erase(ss.begin());
// 			if (ss.empty() || *ss.begin() > x)
// 				vv.push_back(make_pair('i', x)), ss.insert(x);
// 			vv.push_back(make_pair('g', x));
// 		}
// 		else {
// 			if (ss.empty())
// 				ss.insert(1), vv.push_back(make_pair('i', 1));
// 			ss.erase(ss.begin());
// 			vv.push_back(make_pair('r', 0));
// 		}
// 	}
// 	printf("%d\n", (int)vv.size());
// 	for (auto i: vv) {
// 		if (i.first == 'i')
// 			printf("insert %d\n", i.second);
// 		else if (i.first == 'g')
// 			printf("getMin %d\n", i.second);
// 		else
// 			printf("removeMin\n");
// 	}
// 	return 0;
// }

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
	std::ios::sync_with_stdio(false); 
	int n;
	cin>>n;

	pqueue test;
	vector<string> final_answer;
	int counter = 0;

	rep(i,n)
	{
		string temp;
		cin>>temp;

		switch(temp[0])
		{
			case 'i':{
				int number;
				cin>>number;
				test.push(-number);
				// Print statement
				// cout<<temp<<" "<<number<<endl;
				temp += " ";
				temp += to_string(number);
				final_answer.pb(temp);
				counter++;
				break;
			}

			case 'r':{
				if(test.empty())
				{
					// cout<<"insert "<<1<<endl;
					// cout<<temp<<endl;
					string gen = "insert 1";
					final_answer.pb(gen);
					final_answer.pb(temp);
					counter += 2;

				}
				else
				{
					// cout<<temp<<endl;
					final_answer.pb(temp);
					test.pop();
					counter++;
				}
				break;
			}

			case 'g':{

				int number;
				cin>>number;

				if(test.empty())
				{
					// cout<<"insert "<<number<<endl;
					string gen = "insert ";
					gen += to_string(number);
					final_answer.pb(gen);
					test.push(-number);
					gen = "getMin ";
					gen += to_string(number);
					final_answer.pb(gen);
					counter+=2;
				}
				else
				{
					if(-number > test.top())
					{
						// cout<<"insert "<<number<<endl;
						// cout<<temp<<" "<<number<<endl;	
						string gen = "insert ";
						gen += to_string(number);
						final_answer.pb(gen);	

						gen = "getMin ";
						gen += to_string(number);
						final_answer.pb(gen);
						test.push(-number);
						counter+=2;
					}
					else if(-number < test.top())
					{
						while(!test.empty()&&(-number < test.top()))
						{
							// cout<<"removeMin\n";
							final_answer.pb("removeMin");
							counter++;
							test.pop();
						}

						if(test.empty())
						{
							// cout<<"insert "<<number<<endl;
							// cout<<temp<<" "<<number<<endl;
							string gen = "insert ";
							gen += to_string(number);
							final_answer.pb(gen);	

							gen = "getMin ";
							gen += to_string(number);
							final_answer.pb(gen);
							counter += 2;
							test.push(-number);
						}
						else
						{
							if(-number > test.top())
							{
								// cout<<"insert "<<number<<endl;
								// cout<<temp<<" "<<number<<endl;		
								string gen = "insert ";
								gen += to_string(number);
								final_answer.pb(gen);	

								gen = "getMin ";
								gen += to_string(number);
								final_answer.pb(gen);
								test.push(-number);
								counter += 2;
							}
							else
							{
								// cout<<temp<<" "<<number<<endl;
								string gen = "getMin ";
								gen += to_string(number);
								final_answer.pb(gen);
								counter++;
							}
						}

					}
					else
					{
						// cout<<temp<<" "<<number<<endl;
						string gen = "getMin ";
						gen += to_string(number);
						final_answer.pb(gen);
						counter++;
					}
				}
				break;
			}
		}
	}

	cout<<counter<<endl;
	rep(i,counter)
	{
		cout<<final_answer[i]<<endl;
	}
} 
