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

    if(numElements<2 || numElements>15){
        cout << "Invalid Queue range";
        return 0;
    }


    for (int i = 0; i < numElements; i++)
    {
        int type;
        cin >> type;
        if(type%2==0){
            ins.push(type);
        }
        
    }

    if(ins.empty()){
        cout << "No even element is there";
        return 0;
    }
    while(!ins.empty()){
        cout << ins.front() << " ";
        ins.pop();
    }
    
    return 0;
}