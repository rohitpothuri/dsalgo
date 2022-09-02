#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

int main(){
    int n1;
    cin >> n1;
    cin.ignore();
    string programming;
    getline(cin, programming);


    int n2;
    cin >> n2;
    cin.ignore();
    string automata;
    getline(cin, automata);

    int programmingarray[n1];
    int i = 0;
    stringstream ssin(programming);
    while (ssin.good() && i < n1){
        ssin >> programmingarray[i];
        ++i;
    }

    int automataarray[n2];
    int j = 0;
    stringstream ssin2(automata);
    while (ssin2.good() && j < n2){
        ssin2 >> automataarray[j];
        ++j;
    }
    int combined_size = n1+n2;
    int combinedarray[combined_size];

    for (int i = 0; i<combined_size; i++){
      if(i<n1){
        combinedarray[i] = programmingarray[i];
      }
      else if(i>=n1 && i<combined_size){
        combinedarray[i] = automataarray[i-n1];
      }
    }

    for (int i = 0; i<combined_size; i++){
      if(i<combined_size)
        cout << combinedarray[i]<< " ";
      else
        cout << combinedarray[i];  
    }

    int index = -1;
    for (int i = 0; i<combined_size; i++){
      if(combinedarray[i]%2==0)
        index = i;
    }
    cout << "\n";
    int output = -1;
    for (int i = 0; i<combined_size; i++){
      if(combinedarray[i]%2==0 && index==i){
        cout << i;
        output = 0;
      }  
      else if(combinedarray[i]%2==0){
        cout << i << " "; 
        output = 0;
      } 
    }
    if(output==-1)
      cout << output;

    return 0;

}