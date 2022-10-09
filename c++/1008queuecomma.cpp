#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    queue <string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push(substr);
    }
 
    cout << v.back() << endl;
        
}