#include <iostream>
#include <sstream>

using namespace std;

int count_spaces(string s) {
  int count = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ') count++;

  return count;
}

int main(){
    string str;
    getline(cin, str);
    string str1;
    getline(cin, str1);

    int elements = count_spaces(str)+1;

    if(elements<10 || elements>50){
        cout << -1;
    }
    
    string myarray[elements];
    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < elements){
        ssin >> myarray[i];
        ++i;
    }
    int output = -2;
    for(int i=0;i<elements;i++)  
    {  
        if(myarray[i]== str1)
            output=i;
    }
    cout << output+1;

}