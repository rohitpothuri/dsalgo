#include <iostream>
#include <queue>
#include <climits>
#include <string>
using namespace std;

int main()
{
	queue<int> myqueue;
    int N;
    int prevElement = INT_MIN;
    cin >> N;
    if(N<=2 || N>10){
        cout << "Invalid size";
        return 0;
    }

    for(int i=0; i<=N; i++){
        string str;
        cin >> str;
        try{
            int n = stoi(str);

        if(n>prevElement){
            myqueue.push(n);
            prevElement = n;
            }
        }
        catch (std::exception & e)
        {
            cout << "values should only be numbers";
            return 0;
        }   
    }

    if(myqueue.size()<=2){
        cout << "Invalid size";
        return 0;
    }

	while (!myqueue.empty()) {
		
        if(myqueue.size()==1){
           cout << myqueue.front();
        }
        else{
            cout << myqueue.front() <<"\n";
        }
		myqueue.pop();
	}
    cout << endl;
}
