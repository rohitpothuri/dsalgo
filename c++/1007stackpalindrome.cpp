#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
	int length = s.size();
	stack<char> st;
	int i, mid = length / 2;

	for (i = 0; i < mid; i++) {
		st.push(s[i]);
	}
	if (length % 2 != 0) {
		i++;
	}

	char ele;
	while (s[i] != '\0')
	{
		ele = st.top();
		st.pop();
	    if (ele != s[i])
		    return false;
		i++;
	}

return true;
}

int main()
{
	int n;
    cin >> n;
    if(n<=0){
        cout << "Invalid Input";
        return 0;
    }


    queue<string> ins; 

    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        ins.push(s);
    }

    while(!ins.empty()){
        if(isPalindrome(ins.front())){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }    
        ins.pop();
    }

	return 0;
}
