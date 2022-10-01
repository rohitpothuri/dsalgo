#include <iostream>
#include <stack>  
using namespace std;

bool checkExpress(string str){
    int i;
	int N = str.length();

	if(N<=0){
		cout << "String expression length should > 0";
		return 0;
	}

    stack <char> st;
    
    if(str.length() % 2 != 0) return false;
    
    for(int i = 0; i < N; i++){

        if (str[i] == '(' || str[i] == '[') {
            st.push(str[i]);
        } else if(str[i] == ')') {
            if(st.empty() || st.top() != '(') return false;
            st.pop();
        } else if(str[i] == ']') {
            if(st.empty() || st.top() != '[') return false;
            st.pop();
        } 
    }

    return true;
}

int main(){

    string a;
	cin >> a;
    
    if(checkExpress(a)) cout << "Balanced";
    else cout << "Not Balanced";

    return 0;
}