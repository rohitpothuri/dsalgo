#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

int
count_spaces (string s)
{
  int count = 0;
  int sz = s.size ();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ')
      count++;
  return count;
}

void
bubbleSort (int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)

    // Last i elements are already
    // in place
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
	swap (arr[j], arr[j + 1]);
}

int
main ()
{
  string str1;
  getline (cin, str1);

  int elements = count_spaces(str1) + 1;
  int myarray[elements];
  int i = 0;
  stringstream ssin (str1);
  while (ssin.good () && i < elements)
    {
      ssin >> myarray[i];
      ++i;
    }
  bubbleSort(myarray, elements);
  for (int j = 0; j < elements; j++)
    {
      cout << myarray[j] << endl;
    }
  return 0;
}
