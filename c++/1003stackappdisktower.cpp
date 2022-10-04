#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<int> arr, int n)
{

  int t = n, i;

  priority_queue<int> p;

  for (i = 0; i < n; i++)

  {

    p.push(arr[i]);

    while (p.top() == t)

    {

      cout << p.top() << " ";

      p.pop();

      t--;
    }

    cout << "\n";
  }
}

int main()
{

  int N;
  cin >> N;

  vector<int> arr(N);

  for (int i_arr = 0; i_arr < N; i_arr++)
  {

    cin >> arr[i_arr];
  }

  solve(arr, N);
}