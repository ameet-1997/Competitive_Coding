#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
using namespace std;

int const N = 2e5 + 456;

int n, le[N], ri[N], answ[N];
vector<int> a, q, out[N];

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int num;
        scanf("%d",&num);
        a.push_back(num);
    }

    for(int i=0;i<n;++i){
        while(q.size() > 0 && a[q.back()] >= a[i]){
            q.pop_back();
        }
        if(q.size() == 0){
            le[i] = -1;
        }else{
            le[i] = q.back();
        }
        q.push_back(i);
    }

    q.clear();
    for(int i=n-1;i>=0;--i){
        while(q.size() > 0 && a[q.back()] >= a[i]){
            q.pop_back();
        }
        if(q.size() == 0){
            ri[i] = n;
        }else{
            ri[i] = q.back();
        }
        q.push_back(i);
    }

    for(int i=0;i<n;++i){
        int sz = (i - le[i]) + (ri[i] - i - 1);
        out[sz].push_back(a[i]);
    }

    int maxi = 0;
    for(int i=n;i>0;--i){
        for(int j=0;j<out[i].size();++j){
            maxi = max(maxi, out[i][j]);
        }
        answ[i] = maxi;
    }
    
    for(int i=1;i<=n;++i){
        printf("%d ",answ[i]);
    }

    return 0;
}

// #include <bits/stdc++.h>
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

// using namespace std;
// #define f(i,a,b) for(int i=a;i<b;i++)
// #define rep(i,n) f(i,0,n)
// #define fd(i,a,b) for(int i=a;i>=b;i--)
// #define pb push_back
// #define mp make_pair
// #define vi vector< int >
// #define vl vector< ll >
// #define ss second
// #define ff first
// #define ll long long
// #define pii pair< int,int >
// #define pll pair< ll,ll >
// #define sz(a) a.size()
// #define inf (1000*1000*1000+5)
// #define all(a) a.begin(),a.end()
// #define tri pair<int,pii>
// #define vii vector<pii>
// #define vll vector<pll>
// #define viii vector<tri>
// #define mod (1000*1000*1000+7)
// #define pqueue priority_queue< int >
// #define pdqueue priority_queue< int,vi ,greater< int > >

// // std::ios::sync_with_stdio(false); 
// vi bears;
// int main()
// {	
// 	void fill_arrays(vi&, vi&, int);
// 	int n;
// 	cin>>n;
// 	bears.resize(n);

// 	rep(i,n)
// 	{
// 		cin>>bears[i];
// 	}

// 	vi next_lesser(n);
// 	vi prev_lesser(n);
// 	fill(next_lesser.begin(), next_lesser.end(), -1);
// 	fill(prev_lesser.begin(), prev_lesser.end(), -1);

// 	fill_arrays(next_lesser, prev_lesser, n);
// } 




// void fill_arrays(vi& next_lesser, vi& prev_lesser, int n)
// {
// 	stack<pii> greater_stack;

// 	for(int i=0;i<n;++i)
// 	{
// 		while((!greater_stack.empty())&&(greater_stack.top().first >= bears[i]))
// 		{
// 			next_lesser[greater_stack.top().second] = i;
// 			greater_stack.pop();
// 		}
// 		greater_stack.push(mp(bears[i],i));
// 	}

// 	stack<pii> lesser_stack;

// 	for(int i=n-1;i>=0;--i)
// 	{
// 		while((!lesser_stack.empty())&&(lesser_stack.top().first >= bears[i]))
// 		{
// 			prev_lesser[lesser_stack.top().second] = i;
// 			lesser_stack.pop();
// 		}
// 		lesser_stack.push(mp(bears[i],i));
// 	}	

// 	// vector< vi > add(n+1);
// 	set<int> answer;
// 	rep(i,n)
// 	{
// 		answer.insert()
// 	}
// 	vector< vi > sub(n+1);

// 	rep(i,n)
// 	{
// 		int left, right;

// 		if(next_lesser[i] == -1)
// 		{
// 			right = n;
// 		}
// 		else
// 		{
// 			right = next_lesser[i];
// 		}

// 		if(prev_lesser[i] == -1)
// 		{
// 			left = 0;
// 		}
// 		else
// 		{
// 			left = prev_lesser[i]+1;
// 		}

// 		sub[right-left].pb(bears[i]);
// 	}

// 	// Check output

// 	// cout<<"Next\n";
// 	// rep(i,n)
// 	// {
// 	// 	cout<<next_lesser[i]<<" ";
// 	// }
// 	// cout<<endl;
// 	// cout<<"Prev\n";
// 	// rep(i,n)
// 	// {
// 	// 	cout<<prev_lesser[i]<<" ";
// 	// }
// 	// cout<<endl;
// }
