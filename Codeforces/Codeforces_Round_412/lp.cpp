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


vector<vector<double> > SetSimplex( vector<double> maxFunction, 
       vector<vector<double> > A, 
       vector<double> b)
{
 vector<vector<double> > simplex;


 int numVariables = maxFunction.size();
 int numEquations = A.size();
 int numCols = numVariables + numEquations + 1 + 1;


 for(int iRow = 0; iRow < numEquations; iRow++)
 {
  vector<double> row(numCols, 0);
  for(int iCol = 0; iCol < numVariables; iCol++)
  {
   row[iCol] = A[iRow][iCol];
  }
  row[numVariables + iRow] = 1;
  row[numCols - 1] = b[iRow];


  simplex.push_back( row );
 }


 vector<double> lastRow(numCols, 0);
 for(int iVar = 0; iVar < numVariables; iVar++)
 {
  lastRow[iVar] = 0 - maxFunction[iVar];
 }
 lastRow[numVariables + numEquations] = 1;
 simplex.push_back(lastRow);


 return simplex;
}





bool GetPivots(vector<vector<double> > simplex, int & pivotCol, int & pivotRow, bool & noSolution)
{
 int numRows = simplex.size();
 int numCols = simplex[0].size();
 int numVariables = numCols - numRows - 1;


 noSolution = false;


 double min = 0;
 for(int iCol = 0; iCol < numCols - 2; iCol++)
 {
  double value = simplex[numRows - 1][iCol];
  if(value < min)
  {
   pivotCol = iCol;
   min = value;
  }
 }


 if(min == 0)
  return false;


 double minRatio = 0.0;
 bool first = true;
 for(int iRow = 0; iRow < numRows - 1; iRow++)
 {
  double value = simplex[iRow][pivotCol];
  
  if(value > 0.0)
  {
   double colValue = simplex[iRow][numCols - 1];
   double ratio = colValue / value;


   if((first || ratio < minRatio) && ratio >= 0.0)
   {
    minRatio = ratio;
    pivotRow = iRow;
    first = false;
   }
  }
 }


 noSolution = first;
 return !noSolution;
}


vector<double> DoSimplex(vector<vector<double> > simplex, double & max)
{
 int pivotCol, pivotRow;
 int numRows = simplex.size();
 int numCols = simplex[0].size();


 bool noSolution = false;
 while( GetPivots(simplex, pivotCol, pivotRow, noSolution) )
 {
  double pivot = simplex[pivotRow][pivotCol];
  
  for(int iCol = 0; iCol < numCols; iCol++)
  {
   simplex[pivotRow][iCol] /= pivot;
  }


  for(int iRow = 0; iRow < numRows; iRow++)
  {
   if(iRow != pivotRow)
   {
    double ratio =  -1 * simplex[iRow][pivotCol];
    for(int iCol = 0; iCol < numCols; iCol++)
    {
     simplex[iRow][iCol] = simplex[pivotRow][iCol] * ratio + simplex[iRow][iCol];
    }
   }
  }
 }


 if(noSolution)
 {
  vector<double> vec;
  return vec;
 }
 
 //optimo!!!
 max = simplex[numRows-1][numCols-1];
 int numVariables = numCols - numRows - 1;
 vector<double> x(numVariables, 0);
 
 for(int iCol = 0; iCol < numVariables; iCol++)
 {
  bool isUnit = true;
  bool first = true;
  double value;
  for(int j = 0; j < numRows; j++)
  {
   if(simplex[j][iCol] == 1.0 && first)
   {
    first = false;
    value = simplex[j][numCols - 1];
   }
   else if(simplex[j][iCol] != 0.0)
   {
    isUnit = false;
   }
  }


  if(isUnit && !first)
   x[iCol] = value;
  else
   x[iCol] = 0.0;
 }


 return x;
} 


string cleanSpaces(string str)
{
 string space = " ";
 int pos;
 while((pos = str.find(space)) != string::npos)
 {
  str = str.erase(pos, 1);
 }
 return str;
}


vector<double> commaSeparatedStringToDoubleVector(string str)
{
 vector<double> vec;
 while(str.length() > 0)
 {
  int pos = str.find(",");
  if (pos!=string::npos)
  {
   string strNum = str.substr(0, pos);
   strNum = cleanSpaces(strNum);
   vec.push_back(atof(strNum.c_str()));
   str = str.substr(pos+1);
  }
  else
  {
   string strNum = cleanSpaces(str.c_str());
   vec.push_back(atof(strNum.c_str()));
   break;
  }
 }
 return vec;
}



int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int x,y,p,q;
		cin>>x>>y>>p>>q;

		if(p == q)
		{
			if(x == y)
			{
				cout<<"0\n";
				continue;
			}
			else
			{
				cout<<"-1\n";
				continue;
			}
		}

		vector<double> maxFunc;

		maxFunc.push_back(-1);
		maxFunc.push_back(0);
		maxFunc.push_back(0);

		 vector<vector<double> > A(6);
		 
		 A[0].push_back(p);
		 A[0].push_back(-1);
		 A[0].push_back(0);

		 A[1].push_back(-p);
		 A[1].push_back(1);
		 A[1].push_back(0);

		 A[2].push_back(q);
		 A[2].push_back(0);
		 A[2].push_back(-1);


		 A[3].push_back(-q);
		 A[3].push_back(0);
		 A[3].push_back(1);

		 A[4].push_back(0);
		 A[4].push_back(1);
		 A[4].push_back(-1);

		 A[5].push_back(-1);
		 A[5].push_back(0);
		 A[5].push_back(0);
		 
		 vector<double> b;

		 b.push_back(x);
		 b.push_back(-x);
		 b.push_back(y);
		 b.push_back(-y);
		 b.push_back(0);
		 b.push_back(-1);

		 cout<<"Here\n";


		vector<vector<double> > simplex = SetSimplex(maxFunc, A, b);

		cout<<simplex.size()<<" Size\n";

		double max_number;
		vector<double> result = DoSimplex(simplex, max_number);

		auto it = result.begin();

		while(it != result.end())
		{
			cout<<*it<<" ";
			it++;
		}
		cout<<"\n";

		cout<<-max_number<<"\n";
	}

/*string maxFuncStr = "8.0 , 10.0 , 7.0";
 vector<double> maxFunc = commaSeparatedStringToDoubleVector(maxFuncStr);

 vector<vector<double>> A;
                                      //         x1     x2    x3
 A.push_back(commaSeparatedStringToDoubleVector("1.0 , 3.0 , 2.0"));
 A.push_back(commaSeparatedStringToDoubleVector("1.0 , 5.0 , 1.0"));
 
             //  b1     b2
 string bStr = "10.0 , 8.0";
 vector<double> b = commaSeparatedStringToDoubleVector(bStr);

 vector<vector<double>> simplex = SetSimplex(maxFunc, A, b);

 double max;
 vector<double> result = DoSimplex(simplex, max);

 printf("Result: Max = %f\n", max);
 for(int i = 0; i < result.size(); i++)
 {
  printf("x%d = %f ; ", i, result[i]);
 }
 printf("\n----------------------\n");

	*/	

} 