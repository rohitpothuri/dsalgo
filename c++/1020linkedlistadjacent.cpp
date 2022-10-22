#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void twoWaySort()
{

  int N;
  cin >> N;

  if(N>8){
    cout << "N>0 and N<10";
  }
  int n = N+1;
  int arr[n];
  int z=0;
  for(int i=0; i<N; i++){
    cin >> arr[i] ;
    z++;
  }
  cin >> arr[z] ;

	int l = 0, r = n - 1;
	int k = 0;

	while (l < r)
	{
	
		while (arr[l] % 2 != 0)
		{
			l++;
			k++;
		}
		while (arr[r] % 2 == 0 && l < r)
			r--;

		if (l < r)
			swap(arr[l], arr[r]);
	}
	sort(arr, arr + k);
	sort(arr + k, arr + n, greater<int>());

  for (int i = 0; i < N; i++){
    if(arr[i]==arr[i+1]){
      cout << "Duplicates are not allowed";
      return;
    }
  }

  for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	twoWaySort();
	return 0;
}
