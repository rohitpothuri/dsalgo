#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    char str;
    cin>>str;
    char colors[7] = {'V','I','B','G','Y','O','R'};
    int found = 0;
    for(int i=0;i<7;i++){
      if(str == colors[i])
        found = 1;
    }

    if(!isupper(str)){
      cout << "Input character should be uppercased";
      return 0;
    }

    if(found==0){
      cout << "Color not available";
      return 0;
    }
      

    for(int i=0;i<7;i++){
      if(str != colors[i])
        cout << colors[i];
    }
    return 0;

}