#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    queue<long> ins;

    int numElements;
    cin >> numElements;

    int numOperations;
    cin >> numOperations;

    for (int i = 0; i < numElements; i++)
    {
        int type;
        cin >> type;
        ins.push(type);
    }
    
    for(int i=0; i<numOperations; i++){
        int type; 
        long param; 
        cin >> type; 
        switch(type){
            case 1:
                param = ins.front(); 
                ins.pop();
                ins.push(param); 
                break; 
            case 0:
                ins.pop(); 
                break; 
            default: 
                break; 
        }
    }
    while (!ins.empty())
    {
        cout << ins.front() << " ";
        ins.pop();
    }

    return 0;
}