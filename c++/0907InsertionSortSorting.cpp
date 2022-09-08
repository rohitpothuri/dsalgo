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
void swap(string *xp, string *yp)
{
  string temp = *xp;
  *xp = *yp;
  *yp = temp;
}
int main()
{
  int num;
  cin >> num;
  cin.ignore();
  string str1;
  getline(cin, str1);

  string myarray[num];
  int i = 0;
  stringstream ssin(str1);
  while (ssin.good() && i < num)
  {
    ssin >> myarray[i];
    ++i;
  }

  int j, k;

  // One by one move boundary of
  // unsorted subarray
  for (i = 0; i < num - 1; i++)
  {
    k = i;
    for (j = i + 1; j < num; j++)
    {
      if (myarray[j] < myarray[k])
        k = j;
      if (k != i){
        swap(&myarray[k], &myarray[i]);
      }
          
    }
    
  }
  return 0;
}