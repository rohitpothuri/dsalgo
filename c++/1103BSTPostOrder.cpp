#include<iostream>
#include<vector>
using namespace std;
int search(char arr[], int x, int n){
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPostOrder(char in[], char pre[], int n) {
    char root = search(in, pre[0], n);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    cout << pre[0] << " ";
}

int main(){
    char arr1[7], arr2[7];
    char k;
    int n;
    for(int i = 0;i<7;i++){
        cin>>arr1[i];
    }
    for(int i = 0;i<7;i++){
        cin>>arr2[i];
    }
    printPostOrder(arr2, arr1, 7);
    return 0;
}