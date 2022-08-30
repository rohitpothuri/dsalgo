#include<iostream>  
using namespace std;  
int main ()  
{    
    int N;
    cout<<"\nEnter size of Array: ";
    cin>>N;

    if(N>12)
     throw std::invalid_argument( "Deck cannot have more than 13 cards" );
    
    int myarray[N+1], i, elem;
    cout<<"Enter Array Elements: ";
    for(i=0; i<N; i++)
        cin>>myarray[i];
    
    cout<<"\nInput list is \n";
    for(int i=0;i<N;i++)  
    {  
        cout <<myarray[i]<<"\t";  
    }
    
    cout<<"\nEnter Element to Insert: ";
    cin>>elem;
    myarray[i] = elem;
    
    for(int k=1; k<N+1; k++)   
    {  
        int temp = myarray[k];  
        int j= k-1;  
        while(j>=0 && temp <= myarray[j])  
        {  
            myarray[j+1] = myarray[j];   
            j = j-1;  
        }  
        myarray[j+1] = temp;  
    }  
    cout<<"\nSorted list is \n";
    for(int i=0;i<N+1;i++)  
    {  
        if(i==N-1)
            cout <<myarray[i]<<"\t";
        else
        cout <<myarray[i];  
    } 

}