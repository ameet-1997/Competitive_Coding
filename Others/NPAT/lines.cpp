#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> names;
  int counter = 0;
  
  while(!cin.eof())
  {
	string temp;
    // cin>>temp;
    getline(cin,temp,'\n');

    
    names.push_back(temp);
    if(!temp.empty())
    {
		counter++;
    }
    //counter++;
  }
  
//   for(int i=counter/2;i<counter;++i)
//   {
// cout<<names[i]<<"\n";
//   }
  
  for(int i=0;i<counter/2;++i)
  {	
  	if(i == counter/2-1)
  	{
		cout<<names[i];  		
  	}
  	else
  	{
		cout<<names[i]<<"\n";  		
  	}

  }
  
  return 0;
}
  
   
