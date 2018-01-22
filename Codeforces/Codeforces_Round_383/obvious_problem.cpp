#include <iostream>
#include <algorithm>

using namespace std;


int a[1000000];
int b[1000000];

int main ()
{	
	int count(int arr[], int x, int n);
	int first(int arr[], int low, int high, int x, int n);
	int last(int arr[], int low, int high, int x, int n);

	int n,x;
	cin>>n>>x;


	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}

	sort(a,a+n);

	long long int answer = 0;




	for(int i=0;i<n;++i)
	{
		int temp = x^a[i];

		int checking = count(a,temp,n);
		if(checking > 0)
		{
			if(a[i] == temp)
			{
				answer = answer + checking + 1;
			}
			else
			{
				answer = answer + checking;
			}
		}
	}

	answer = answer/2;

	cout<<answer<<"\n";

}


/* if x is present in arr[] then returns the count of occurrences of x, 
   otherwise returns -1. */
int count(int arr[], int x, int n)
{	
	int first(int arr[], int low, int high, int x, int n);
	int last(int arr[], int low, int high, int x, int n);


  int i; // index of first occurrence of x in arr[0..n-1]
  int j; // index of last occurrence of x in arr[0..n-1]
     
  /* get the index of first occurrence of x */
  i = first(arr, 0, n-1, x, n);
 
  /* If x doesn't exist in arr[] then return -1 */
  if(i == -1)
    return i;
    
  /* Else get the index of last occurrence of x. Note that we 
      are only looking in the subarray after first occurrence */  
  j = last(arr, i, n-1, x, n);     
    
  /* return count */
  return j-i+1;
}
 
/* if x is present in arr[] then returns the index of FIRST occurrence 
   of x in arr[0..n-1], otherwise returns -1 */
int first(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  return -1;
}
 
 
/* if x is present in arr[] then returns the index of LAST occurrence 
   of x in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);      
  }
  return -1;
}

