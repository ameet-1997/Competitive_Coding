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

// Lazy Segment Tree

vl tree(300000);
vl lazy(300000);
viii commands(100000);
// map<int,int> tree_mapping;
vl answer(100001);

int main()
{	
	void build(int,int,int);
	void updateRange(ll node, ll start, ll end, ll l, ll r, ll val);
	ll queryRange(ll node, ll start, ll end, ll l, ll r);

	int test;
	cin>>test;

	while(test--)
	{
		int n,num_commands;
		cin>>n>>num_commands;

		fill(tree.begin(), tree.begin()+3*num_commands, 0);
		fill(lazy.begin(), lazy.begin()+3*num_commands, 0);
		fill(answer.begin(), answer.begin()+n+1, 0);
		// tree_mapping.erase(tree_mapping.begin(), tree_mapping.end());

		rep(i,num_commands)
		{
			cin>>commands[i].ff>>commands[i].ss.ff>>commands[i].ss.ss;
			commands[i].ss.ff--;	commands[i].ss.ss--;
		}

		build(0,0,num_commands-1);

		// cout<<"Testing if tree is built: Value is:: "<<queryRange(0, 0, num_commands-1, 0, 4)<<endl;

		fd(i,num_commands-1,0)
		{
			if(commands[i].ff == 2)
			{	
				int temp = queryRange(0, 0, num_commands-1, i, i);
				// cout<<"In node:: "<<i<<"with value:: "<<temp<<endl;
				updateRange(0, 0, num_commands-1, commands[i].ss.ff, commands[i].ss.ss, temp);
				updateRange(0,0, num_commands-1,i,i,0);
				// updateRange(0, 0, num_commands-1, commands[i].ss.ff, commands[i].ss.ss,);
			}
		}

		rep(i,num_commands)
		{
			if(commands[i].ff == 1)
			{
				int temp = queryRange(0, 0, num_commands-1, i, i);
				answer[commands[i].ss.ff] += temp;
				answer[commands[i].ss.ss+1] -= temp;
			}
		}

		f(i,1,n)
		{
			answer[i] = answer[i-1] + answer[i];
			answer[i]%=mod;
		}

		rep(i,n)
		{
			cout<<answer[i]<<" ";
		}
		cout<<endl;
	}
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = 1;
        // tree_mapping[start] = node;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node+1, start, mid);
        // Recurse on the right child
        build(2*node+2, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node+1] + tree[2*node+2];
        tree[node] %= mod;
    }
}

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        tree[node] %= mod;
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] %= mod;
            lazy[node*2+2] += lazy[node];                // Mark child as lazy
            lazy[node*2+2] %= mod;
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        tree[node] %= mod;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2+1] += val;
            lazy[node*2+1] %= mod;
            lazy[node*2+2] += val;
            lazy[node*2+2] %= mod;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);        // Updating left child
    updateRange(node*2+2, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2+1] + tree[node*2+2];        // Updating root with max value 
    tree[node] %= mod;
}


ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        tree[node] %= mod;
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] %= mod;
            lazy[node*2+2] += lazy[node];    // Mark child as lazy
            lazy[node*2+2] %= mod;
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2+1, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 2, mid + 1, end, l, r); // Query right child
    return (p1 + p2) % mod;
}