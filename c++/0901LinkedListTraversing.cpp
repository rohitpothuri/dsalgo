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

int main()
{
  string str1;
  getline(cin, str1);

  int elements = count_spaces(str1) + 1;

  if (elements<=0)
  {
    cout << "Invalid Range";
    return 0;
  }

  int myarray[elements];
  int i = 0;
  stringstream ssin(str1);
  while (ssin.good() && i < elements)
  {
    ssin >> myarray[i];
    ++i;
  }
  int odd = 0;
  for (int i = 0; i < elements; i++)
  {
    if (myarray[i] % 2 != 0 && myarray[i]!=-1)
      odd = odd + 1;
  }
  if(odd==0)
  cout << "No odd number present";
  else
  cout << odd;
  return 0;
}