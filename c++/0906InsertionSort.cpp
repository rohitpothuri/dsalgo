#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

using namespace std;

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] < key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 

        arr[j + 1] = key; 
    } 
}

int main() {
    int k;
    cin>>k; 

    if(k<0 || k>50){
      cout << "K>0 & K<50";
      return 0;
    }

    cin.ignore();
    string denominations;
    getline(cin, denominations);

    int denominationsarray[k];
    int i = 0;
    stringstream ssin(denominations);
    while (ssin.good() && i < k){
        ssin >> denominationsarray[i];
        if(denominationsarray[i]<=0 || denominationsarray[i]>100){
            cout << "Z>0 & Z<100";
            return 0;
            break;
            
        }
        ++i;
    }

    insertionSort(denominationsarray,k);

    for (i = 0; i < k; i++) 
        cout << denominationsarray[i] << " "; 
    cout << endl;
  
    return 0;
}