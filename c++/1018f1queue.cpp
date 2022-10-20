#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
    queue <string> f1cars;
    queue <string> f1carscopy;
    int numCars;
    cin >> numCars;

    for(int i=0; i<numCars; i++){
        string name;
        cin >> name;
        f1cars.push(name);
    }

    for(int i = 0; i<3; i++){
       string front = f1cars.front();
       f1cars.pop();
       f1cars.push(front); 

       f1carscopy = f1cars;

       while(!f1carscopy.empty()){
        cout << f1carscopy.front() << " ";
        f1carscopy.pop(); 
       }
       cout << endl;

    }

    cout << f1cars.front();
        
}