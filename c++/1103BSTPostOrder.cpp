#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int count_spaces(string s) {
  int count = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ') count++;

  return count;
}

int search(int arr[], int x, int n)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
	int root = search(in, pre[0], n);
	if (root != 0)
		printPostOrder(in, pre + 1, root);
	if (root != n - 1)
		printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
	cout << pre[0] << " ";
}

int main()
{
  int rawInput;
  vector<int> numbers1;
  while( getline( cin, rawInput, ' ' ) )
  {
    numbers1.push_back(atoi(rawInput));
  }

  string rawInput2;
  vector<int> numbers2;
  while( getline( cin, rawInput2, ' ' ) )
  {
    numbers2.push_back(rawInput2);
  }

	int n0 = sizeof(numbers2) / sizeof(numbers2[0]);
	printPostOrder(numbers2, numbers1, n0);
	return 0;
}
