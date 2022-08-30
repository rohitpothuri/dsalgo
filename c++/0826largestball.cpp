#include <iostream>
#include <cstring>
#include<string.h>
using namespace std;

int main() {
    
    
   int N;
    //cout<<"\nEnter number of tries: ";
   cin>>N;
   if(N<0 || N>5)
     throw std::invalid_argument( "Cannot play more than 5 times" );
    
  char str1[100];
  cin.getline(str1,100);
  char str2[100];
  cin.getline(str2,100);
  
  char *ptr1;
  ptr1 = strtok(str1," ");
  int stra1;
  
  char *ptr2;
  ptr2 = strtok(str2," ");
  int stra2;
  
  int max1 = 0;
  while(ptr1!=NULL)
  {
      if(atoi(ptr1)>max1)
        max1 = atoi(ptr1);
      ptr1 = strtok(NULL," ");
  }
  cout << "\n" << max1;
  
  int max2 = 0;
  while(ptr2!=NULL)
  {
      if(atoi(ptr2)>max2)
        max2 = atoi(ptr2);
      ptr2 = strtok(NULL," ");
  }
  cout << "\n" << max2;
 
return 0;
}