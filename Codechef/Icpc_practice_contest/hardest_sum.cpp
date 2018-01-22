#include <stdio.h>

#define ARRAY_SIZE 1000


int matrix[ARRAY_SIZE][ARRAY_SIZE],sub_left[ARRAY_SIZE][ARRAY_SIZE],sub_right[ARRAY_SIZE][ARRAY_SIZE],sub_top[ARRAY_SIZE][ARRAY_SIZE],sub_bottom[ARRAY_SIZE][ARRAY_SIZE];

//Replace with long int--------------------int--------------------int--------------------int--------------------

int main()
{
	int test;
	scanf("%d",&test);


	for(int tester=0;tester<test;++tester)
	{
		int n,m;

		int final_answer;

		scanf("%d%d",&n,&m);

		for(int i=0;i<n;++i)		//Taking matrix values
		{
			for(int j=0;j<m;++j)
			{
				scanf("%d",&matrix[i][j]);
			}
		}


		for(int i=0;i<n;++i)		//For right most column
		{
			sub_right[i][m-1] = matrix[i][m-1];
		}

		for(int i=0;i<n;++i)		//For left most column
		{
			sub_left[i][0] = matrix[i][0];
		}


		for(int i=0;i<m;++i)		//For top most row
		{
			sub_top[0][i] = matrix[0][i];
		}

		for(int i=0;i<m;++i)		//For bottom most row
		{
			sub_bottom[n-1][i] = matrix[n-1][i];
		}



		//Initialised all the values.....to compute the minimum subarray sums


		//Calculating the minimum subarray sums for sub_right


		for(int i=0;i<n;++i)
		{
			for(int j=m-2;j>=0;j--)
			{
				if(sub_right[i][j+1]<0)
				{
					sub_right[i][j]=sub_right[i][j+1]+matrix[i][j];
				}
				else
				{
					sub_right[i][j]=matrix[i][j];
				}
			}	
		}
		

		//Stored the values for sub_right







		//Calculating the minimum subarray sums for sub_left


		for(int i=0;i<n;++i)
		{
			for(int j=1;j<=m-1;++j)
			{
				if(sub_left[i][j-1]<0)
				{
					sub_left[i][j]=sub_left[i][j-1]+matrix[i][j];
				}
				else
				{
					sub_left[i][j]=matrix[i][j];
				}
			}	
		}
		

		//Stored the values for sub_left




		//Calculating the minimum subarray sums for sub_top


		for(int j=0;j<m;++j)
		{
			for(int i=1;i<=n-1;++i)
			{
				if(sub_top[i-1][j]<0)
				{
					sub_top[i][j] = sub_top[i-1][j] + matrix[i][j];
				}
				else
				{
					sub_top[i][j] = matrix[i][j];
				}
			}
		}

		//Stores the values for sub_top







		//Calculating the minimum subarray sums for sub_bottom


		for(int j=0;j<m;++j)
		{
			for(int i=n-2;i>=0;--i)
			{
				if(sub_bottom[i+1][j]<0)
				{
					sub_bottom[i][j] = sub_bottom[i+1][j] + matrix[i][j];
				}
				else
				{
					sub_bottom[i][j] = matrix[i][j];
				}
			}
		}

		//Stores the values for sub_bottom



		/*for(int i=0;i<n;++i)		//Sub left
		{
			for(int j=0;j<m;++j)
			{
				printf("%d ",sub_left[i][j]);
			}

			printf("\n");
		}

		printf("\n");


		for(int i=0;i<n;++i)		//Sub right
		{
			for(int j=0;j<m;++j)
			{
				printf("%d ",sub_right[i][j]);
			}

			printf("\n");
		}

		printf("\n");


		for(int i=0;i<n;++i)		//Sub top
		{
			for(int j=0;j<m;++j)
			{
				printf("%d ",sub_top[i][j]);
			}

			printf("\n");
		}

		printf("\n");



		for(int i=0;i<n;++i)		//Sub bottom
		{
			for(int j=0;j<m;++j)
			{
				printf("%d ",sub_bottom[i][j]);
			}

			printf("\n");
		}

		printf("\n");*/

		final_answer = matrix[0][0];

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				int check = sub_left[i][j] + sub_right[i][j] + sub_top[i][j] + sub_bottom[i][j] - 3*matrix[i][j];
				if(check<final_answer)
				{
					final_answer = check;
				}
			}
		}


		printf("%d\n",final_answer);


	}
} 
