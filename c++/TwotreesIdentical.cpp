#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n1, n2, flag =0;
    cin>>n1;
    int arr1[n1];
    for(int i =0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    if(n1 == n2)
    {
        for(int i=0;i<n1;i++)
        {
            if(arr1[i]!=arr2[i])
            {
                flag = 1;
                cout<<"Both trees are not identical";
                break;
            }
        }
        if(flag == 0)
        {
            cout<<"Both trees are identical";
        }
    }
    else
    {
        cout<<"Both trees are not identical";
    }
    return 0;
}