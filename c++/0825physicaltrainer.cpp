#include<iostream>  
using namespace std;  
int main ()  
{    
    int N;
    cout<<"\nEnter Number of Students: ";
    cin>>N;
    
    int myarray[N], i, elem;
    cout<<"Enter Student heights: ";
    for(i=0; i<N; i++)
        cin>>myarray[i];
    
    cout<<"\nInput list is \n";
    for(int i=0;i<N;i++)  
    {  
        cout <<myarray[i]<<"\t";  
    }

    int l = 0;

    for(int i=0;i<N-1;i++)  
     {  
        if(myarray[i]%2!=0 && myarray[i+1]%2!=0){
            l = l+1;

        } 
    }

    cout<<"\n"<<"odd pairs count is ";
    int myarray2[N+l];
    cout <<"\n"<<l<<"\n";
    int limit = (sizeof(myarray) / sizeof(int))-1;
    int v=0;
    for(int i = 0;i<limit;i++){  

        if(myarray[i]%2!=0 && myarray[i+1]%2!=0 && ((myarray[i]+myarray[i+1])/2==myarray[i+2])){
            myarray2[v] = myarray[i];
            v = v+1;
            myarray2[v] = myarray[i+2];
            v = v+1;
            myarray2[v] = myarray[i+1];

        }
        else{
            myarray2[v] = myarray[i];
            v = v+1;
            myarray2[v] = myarray[i+1];
        }
    }

    for(int i=0;i<12;i++)  
    {  
        cout <<myarray2[i]<<"\t";  
    }

}