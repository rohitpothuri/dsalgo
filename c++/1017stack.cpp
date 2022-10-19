#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    stack<string> stack;
    string k;
    int c , n;
    cin>>c;
    while(c == 1){
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>k;
            stack.push(k);
        }
        cin>>c;
    }
    cout<<stack.top()<<endl;
    stack.pop();
    while(!stack.empty()){
        cout<<stack.top()<<' ';
        stack.pop();
    }
    return 0;
}