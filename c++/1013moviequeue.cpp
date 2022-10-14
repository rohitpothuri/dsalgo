#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
    queue <string> v;
    int seats;
    cin >> seats;
    int people;
    cin >> people;

    for(int i=0; i<seats; i++){
        string name;
        cin >> name;
        v.push(name);
    }

    if(people>seats){
        cout << "Houseful";
        return 0;
    }
    else{
        cout << "Booked";
        return 0;
    }
        
}