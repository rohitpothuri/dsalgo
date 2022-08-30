#include<iostream>  
using namespace std;  
int main ()  
{    
    int N;
    //cout<<"\nEnter number of tries: ";
    cin>>N;
    if(N<0 || N>5)
     throw std::invalid_argument( "Cannot play more than 5 times" );
    
    int myarray[N][5]; 
    for(int t=0; t<N; t++){
        cout<<"Enter Array Elements: ";
        for(int i=0; i<6; i++)
            cin>>myarray[t][i];
    }
    
    for (int i = 0; i < N; i++)
    {
        int max = myarray[i][0];
        for (int j = 0; j < 6; j++)
        {
            if (myarray[i][j] > max) {
                max = myarray[i][j];
            }
        }
        cout<<"\n"<<max;
    }
    
   return 0; 

}