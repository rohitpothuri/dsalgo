#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<arr[(n-1)/2]<<endl;
    n= n-1;
    cout<<arr[(n-1)/2];
    return 0;
}