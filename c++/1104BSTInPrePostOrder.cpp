#include <iostream>
using namespace std;
int main() {
  const int MAX_SIZE = 100;
  int nums[MAX_SIZE]; 
  int a;
  int i=0;
  while (std::cin >> a) {
    nums[i++] = a;
  }

  for(int z = 0; z<i; z++){
    cout << nums[z];
  }

  // do your output
}