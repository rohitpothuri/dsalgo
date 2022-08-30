#include<iostream>
#include<string.h>
using namespace std; 


int main ()  
{    
    int N;
    cin>>N;

    if(N!=8){
        cout<<"\n"<<"Size must be 8 ";
    }

    string lectures[N];
    
    for(int i=0; i<N; i++)
        cin>>lectures[i];

    int counter = 0;

    for(int i=0;i<N;i++)  
    {  
        if(lectures[i]=="JAVA"){
            counter = counter + 1;
        }
    }
    cout <<"JAVA lecture is repeating "<<counter<<" times"<<endl;
}