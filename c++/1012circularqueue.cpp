#include <iostream>
using namespace std;

int main()
{
  char arr[7];
  int front = -1;
  int rear = -1;

  int n;
  char c;
  while (cin >> n)
  {
    if (n == 1)
    {
      if (front == -1)
        front++;
      if (rear > 5)
      {
        cout << "OVERFLOW";
        return 0;
      }
      rear++;
      cin >> arr[rear];
      continue;
    }
    
    if (n == 2)
      front++;
    else
    {
      cout << arr[front] << endl;
      cout << arr[rear] << endl;
    }
  }
  return 0;
}