
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define NO_OF_CHARS 256
 

// A utility function to get maximum of two integers

int max(int a, int b)

{

    return (a > b) ? a : b;

}

 

// The preprocessing function for Boyer Moore's bad character heuristic

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])

{

    int i;

 

    // Initialize all occurrences as -1

    for (i = 0; i < NO_OF_CHARS; i++)

        badchar[i] = -1;

 

    // Fill the actual value of last occurrence of a character

    for (i = 0; i < size; i++)

        badchar[(int) str[i]] = i;

}

 

int search(char *txt, char *pat)

{
  int count=0;
    int m = strlen(pat);

    int n = strlen(txt);

 

    int badchar[NO_OF_CHARS];

 

    badCharHeuristic(pat, m, badchar);

 

    int s = 0; // s is shift of the pattern with respect to text

    while (s <= (n - m))

    {

        int j = m - 1;

 

        while (j >= 0 && pat[j] == txt[s + j])

            j--;

 

        if (j < 0)

        {

            //printf("\n pattern occurs at shift = %d", s);
            count++;

 

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

 

        }

 

        else

            s += max(1, j - badchar[txt[s + j]]);

    }

    return count;

}

 


/*void computeLPSArray(char *pat, int M, int *lps);
 
int KMPSearch(char *pat, char *txt)
{   int value=0;
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        //printf("Found pattern at index %d \n", i-j);
        value++;
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return value;
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }

 
}*/
 
// Driver program to test above function
int main()
{
   int n;
   scanf("%d",&n);

   char **string;

   string=(char**) malloc(sizeof(char*)*n);

   for(int i=0;i<n;++i)
   {  string[i]=(char*) malloc(sizeof(char)*100010);
    scanf("%s",string[i]);
   }





   char w[1000010];

   int q;

   scanf("%d",&q);

   for(int j=0;j<q;++j)
   {
    int x,y;
    int number=0,total=0;
    scanf("%d%d",&x,&y);

    int p=0;

    while((string[x-1][p]==string[y-1][p])&&(string[x-1][p]!='\0')&&(string[y-1][p]!='\0'))
    {
      w[p]=string[x-1][p];
      p++;
    }
    w[p]='\0';

    if(w[0]=='\0')
    {
      printf("0\n");
    }
    else
    {
      for(int z=0;z<n;++z)
      {
        number=search(string[z],w);
        total=total+number;
      }

      printf("%d\n",total);
    }




   }

   for(int i=0;i<n;++i)
   {
    free(string[i]);
   }
   free(string);
} 
