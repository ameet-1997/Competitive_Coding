#include<stdio.h>

int *a;
int n;

int main()
{	
	int quicksort(int,int);
	
	printf("Enter the number of elements you want to enter : ");
	scanf("%d",&n);
	a=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	
	printf("The sorted elements are : ");
	for(int i=0;i<n;++i)
	{
		printf("  %d  ",a[i]);
	}
	delete[] a;
	return 0;
}

void quicksort(int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = a[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };
      
    printf("-----The sorted elements are : ------");
	for(int i=0;i<n;++i)
	{
		printf("  %d  ",a[i]);
	}
	printf("\n");
 
      /* recursion */
      if (left < j)
            quicksort(left, j);
      if (i < right)
            quicksort(i, right);
}
