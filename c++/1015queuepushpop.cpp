#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    queue<int> ins;
    queue<int> out;

    int numOperations;
    cin >> numOperations;
    
    for(int i=0; i<numOperations; i++){
        int type; 
        int param; 
        int front;
        cin >> type; 
        switch(type){
            case 1:
                cin >> param;
                ins.push(param);
                break; 
            case 0:
                front = ins.front();
                out.push(front);
                ins.pop(); 
                break; 
            default: 
                break; 
        }
    }
    while (!out.empty())
    {
        cout << out.front() << " ";
        out.pop();
    }

    return 0;
}