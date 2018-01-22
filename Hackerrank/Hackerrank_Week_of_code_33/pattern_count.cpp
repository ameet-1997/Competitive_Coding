#include <bits/stdc++.h>

using namespace std;

int patternCount(string s){
    int len = s.length();
    
    bool flag1 = false;
    bool flag2 = false;
    int count = 0;
    
    for(int i=0;i<len;++i)
    {
    	if((s[i] == '1')&&(flag1))
    	{	
    		if(flag2)
    		{
	    		flag1 = true;
	    		count++;
			}
			flag2 = false;

		}
		else if((s[i] == '1')&&(!flag1))
		{
			flag1 = true;
			flag2 = false;
		}
		else if(s[i] == '0')
		{
			flag2 = true;
		}
		else
		{
			flag1 = false;
			flag2 = false;
		}
	}
	
	return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = patternCount(s);
        cout << result << endl;
    }
    return 0;
}

