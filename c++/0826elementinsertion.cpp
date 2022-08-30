#include<iostream>  
using namespace std;  

int count_digit(int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
    }

 int sumNumber(int number) {
    int sum=0,m;          
    while(number>0){    
        m=number%10;    
        sum=sum+m;    
        number=number/10;    
    } 
    return sum;
    }   

int main ()  
{    
    int N;
    //cout<<"\nEnter size of Array: ";
    cin>>N;

    if(N<0 || N>100)
     throw std::invalid_argument( "The length of array (size) should be 0 =< L < 100" );

    int myarray[N];

    int n;
    //cout<<"\nEnter number of elements to insert: ";
    cin>>n;

    //cout<<"\nEnter "<< n <<" number of element : ";
    for(int i=0; i<N; i++){
        if(i<n)
            cin>>myarray[i];   
        else
           myarray[i]=0;           
    }
     

    int elem;
    //cout<<"\nEnter the number to insert in to array: ";
    cin>>elem;

    if(N==n)
     cout<<"Insertion is not possible becouse Array Overflow.. !!";

    int sumDigits = sumNumber(elem);

    while(count_digit(sumDigits)>1){
        sumDigits = sumNumber(sumDigits);
    }

    int myarray2[N];


    for(int i=0;i<N;i++)  
    {  
        
        if(i<(sumDigits-1)){
            myarray2[i] = myarray[i];
        }
        else if(i==(sumDigits-1)) {
            myarray2[i] = elem;
        }
        else{
            myarray2[i] = myarray[i-1];
        }
    } 

    for(int i=0;i<N;i++)  
    {  
        if(i<N-1)
            cout <<myarray2[i]<<"\t";
        else
            cout <<myarray2[i];  
    }


}