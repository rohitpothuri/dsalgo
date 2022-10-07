#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

 
void reverseQueueFirstKElements(int k, queue<int>& Queue)
{
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;
 
    stack<int> Stack;
    for (int i = 0; i < k; i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }
 
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
 
    for (int i = 0; i < Queue.size() - k; i++) {
        Queue.push(Queue.front());
        Queue.pop();
    }
}
 
void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
 
int main()
{
    queue<int> Queue;
    int n;
    cin >> n;

    if(n!=5){
        cout << "Invalid input";
        return 0;
    }

    for (int i=0; i<n; i++){
        int N;
        cin >> N;
        Queue.push(N);
    }
    int k;
    cin >> k;
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
}