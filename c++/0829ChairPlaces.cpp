#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int N;
    cin>>N;
    cin.ignore();
    string str;
    getline(cin, str);
    string chairs[N];
    string newChairs[N+1];

    int n;
    cin>>n;
    cin.ignore();

    string person;
    cin>>person;

    if(n<=0 || n>N+1){
        cout<<"Invalid Position";
        return 0;
    }
        

    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < 4){
        ssin >> chairs[i];
        ++i;
    }

    int pos = 0;
    for(int i=0; i<N+1; i++){
        if(i<n-1){
            newChairs[pos] = chairs[i];
        }
        else if(i==n-1){
            newChairs[pos] = person;
        }
        else{
            newChairs[pos] = chairs[i-1];
        } 
        pos = pos+1;
    }
    for(int i=0;i<N+1;i++)  
    {  
        if(i<N)
            cout <<newChairs[i]<<"\t";
        else
            cout <<newChairs[i];  
    }


}