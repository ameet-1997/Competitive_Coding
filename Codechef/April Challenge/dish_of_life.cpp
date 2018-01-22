#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
// setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints
// xxx77
// setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) f(i, 0, n)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define ss second
#define ff first
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define inf (1000 * 1000 * 1000 + 5)
#define all(a) a.begin(), a.end()
#define tri pair<int, pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000 * 1000 * 1000 + 7)
#define pqueue priority_queue<int>
#define pdqueue priority_queue<int, vi, greater<int> >

// std::ios::sync_with_stdio(false);

int main()
{
    // sad, some, all

    vi all_covered(100000);

    int test;
    cin >> test;

    while (test--)
    {
        int n, k; // n islands and k ingredients
        cin >> n >> k;
        fill(all_covered.begin(), all_covered.begin() + k,
            0); // To check if the ingredient i is present or not

        vector<vector<int> > islands(100000);

        for (int i = 0; i < n; ++i)
        {
            int number_of_ing;
            cin >> number_of_ing;
            int temp;

            for (int j = 0; j < number_of_ing; ++j)
            {
                cin >> temp;
                all_covered[temp - 1]++;
                islands[i].pb(temp - 1);
            }
        }

        int flag = 2;

        for (int i = 0; i < k; ++i)
        {
            if (all_covered[i] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag != 0)
        {
            for (int i = 0; i < n; ++i)
            {
                int flag1 = 0;
                auto it = islands[i].begin();

                while (it != islands[i].end())
                {
                    if (all_covered[*it] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                    it++;
                }

                if (flag1 == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            cout << "sad\n";
        }
        else if (flag == 1)
        {
            cout << "some\n";
        }
        else
        {
            cout << "all\n";
        }
    }
}