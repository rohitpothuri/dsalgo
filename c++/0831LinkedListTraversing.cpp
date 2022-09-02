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
  int n;
  cin>> n;
  cin.ignore();
  string str1;
  getline(cin, str1);

  int elements = count_spaces(str1) + 1;

  if(n <= 0 || n >= 7 || elements <= 0 || elements >= 7 || n!=elements){
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
  int even = 0;
  for (int i = 0; i < elements; i++)
  {
    if (myarray[i] % 2 == 0)
      even += myarray[i];
    else
      odd += myarray[i];
  }
  cout<< odd<<" "<<even;
  return 0;
}