#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

void selectionSort(int a[], int n) {
   int i, j, max, temp;
   for (i = 0; i < n - 1; i++) {
      max = i;
      for (j = i + 1; j < n; j++)
      if (a[j] > a[max])
      max = j;
      temp = a[i];
      a[i] = a[max];
      a[max] = temp;
   }
  }

int main(){
    int n1;
    cin >> n1;
    cin.ignore();
    int myArray1[n1];
    if(n1<1 || n1>20){
      cout << "Invalid Array";
      return 0;
    }
    int i=0;
    while (i < n1) {
      cin >> myArray1[i];
      if(i>0 && (myArray1[i]>myArray1[i-1])){
        cout << "Incorrect Array Elements";
        return 0;
      }
      i++;
    }   

    int n2;
    cin >> n2;
    int myArray2[n2];
    if(n2<1 || n2>20 || n1==n2){
      cout << "Invalid Array";
      return 0;
    }
    int j=0;
    while (j < n2) {
      cin >> myArray2[j];
      if(j>0 && (myArray2[j]>myArray2[j-1])){
        cout << "Incorrect Array Elements";
        return 0;
      }
      j++;
    } 

    int combined_size = n1+n2;
    int combinedarray[combined_size];

    for (int i = 0; i<combined_size; i++){
      if(i<n1){
        combinedarray[i] = myArray1[i];
      }
      else if(i>=n1 && i<combined_size){
        combinedarray[i] = myArray2[i-n1];
      }
    }

    selectionSort(combinedarray, combined_size);

    for(int i=0; i<combined_size;i++){
      if(i==combined_size-1)
        cout << combinedarray[i];
       else
        cout << combinedarray[i] << "\n";
    }

    return 0;

}