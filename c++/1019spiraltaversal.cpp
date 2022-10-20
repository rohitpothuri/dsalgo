#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

  int loops;
  int numElements;

void spiralprint(int c, int d) 
{ 


   int arr[c][d];
    for(int i = 0; i < loops; i++){ 
    for(int j = 0; j < numElements; j++){
        cin >> arr[i][j];
    }
    }

  int i, a = 0, b = 0; 
  while (a < c && b < d) { 
    for (i = b; i < d; ++i) { 
      cout << arr[a][i] << " "; 
    } 
    a++; 

    for (i = a; i < c; ++i) { 
      cout << arr[i][d - 1] << " "; 
    } 
    d--; 
    if (a < c) { 
      for (i = d- 1; i >= b; --i) { 
        cout << arr[c - 1][i] << " "; 
      } 
      c--; 
    } 
    if (b < d) { 
      for (i = c - 1; i >= a; --i) { 
        cout << arr[i][b] << " "; 
      } 
      b++; 
    } 
  } 
} 

int count_spaces(string s) {
  int count = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ') count++;

  return count;
}


int main() 
{ 


  string str;
  getline(cin, str);
  int elements = count_spaces(str)+1;
    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < elements){

        if(i==0){
            ssin >> loops;
        }
        else{
            ssin >> numElements;
        }
        ++i;
    }

  spiralprint(loops, numElements);
  return 0; 
} 