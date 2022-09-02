#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

int count_spaces(string s)
{
  int count = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ')
      count++;
  return count;
}
 
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

bool areDistinct(int firstElement, int size, int numElements)
{
    int myarray1[numElements];
    int first = firstElement;
 
    for (int i = 0; i < numElements; i++) {
       myarray1[i] = first;
       first = first + 1;
    }

    int size_of_myarray1 = sizeof(myarray1);
 
    return (size == size_of_myarray1);
}
 
int main(void)
{

  string str1;
  getline(cin, str1);

  int elements = count_spaces(str1) + 1;

  int n;
  cin>> n;

  int myarray[elements];
  int i = 0;
  stringstream ssin(str1);
  while (ssin.good() && i < elements)
  {
    ssin >> myarray[i];
    ++i;
  }

  int size_of_array =  sizeof(myarray)/sizeof(myarray[0]);

  for(int i=0; i<elements-1; i++){
    if(myarray[i]>myarray[i+1]){
        cout << -1;
        return -1;
    }
  }

  if(size_of_array< 1 || size_of_array> 104 || myarray[0]<-104 || n>104 || !(areDistinct(myarray[0], sizeof(myarray), size_of_array))){
    cout << -1;
  }

  int result = binarySearch(myarray, 0, elements - 1, n);
  (result == -1)
      ? cout << -1
      : cout << result;
  return 0;
}