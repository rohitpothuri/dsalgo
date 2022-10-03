#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<string> stack;
    int n;
    cin >> n;
    if(n<=0){
        cout << "Empty Box";
        return 0;
    }

    if(n>6){
        cout << "Full Box";
        return 0;
    }

    for(int i=0; i<n; i++){
        string book;
        cin >> book;
        stack.push(book);
    }
    int counter  = 0;
	while (!stack.empty()) {
		cout << stack.top();
        if(counter <n-1){
            cout << "->";
        }
        counter ++;
		stack.pop();
	}
}
