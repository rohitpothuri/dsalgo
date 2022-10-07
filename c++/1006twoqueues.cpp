#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

void transfer(stack<long>& from, stack<long>& to){
    while(from.empty()==false){
        to.push(from.top()); 
        from.pop(); 
    }
}

int main() {
    stack<long> outs; 
    stack<long> ins; 
    
    int N; 
    cin >> N; 
    for(int i=0; i<N; i++){
        int type; 
        long param; 
        cin >> type; 
        switch(type){
            case 1:
                cin >> param; 
                ins.push(param); 
                break; 
            case 2:
                if (outs.empty()){
                    transfer(ins, outs); 
                }
                outs.pop(); 
                break; 
            case 3:
                if (outs.empty()){
                    transfer(ins, outs); 
                }
                cout << outs.top() << endl; 
                break; 
            default: 
                break; 
        }
    }
    return 0;
}