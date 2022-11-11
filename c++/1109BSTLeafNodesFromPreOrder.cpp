#include<iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
 
struct node* newNode (int data)
{
    struct node* temp =
(struct node *) malloc(sizeof(struct node));
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

void printLeafNodes(node* root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
    if (root->left)
       printLeafNodes(root->left);
    if (root->right)
       printLeafNodes(root->right);
}

node* constructTreeUtil(int pre[], int* preIndex, int low,
                        int high, int size)
{
    if (*preIndex >= size || low > high)
        return NULL;
    node* root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
 
    if (low == high)
        return root;
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;

    root->left = constructTreeUtil(pre, preIndex, *preIndex,
                                   i - 1, size);
    root->right
        = constructTreeUtil(pre, preIndex, i, high, size);
 
    return root;
}
 
node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
                             size);
}

int main(){
    int n= 0;
    cin>>n;
    int ar[n];
    
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        ar[i] = k;
    }
    struct node *root = constructTree(ar, n);
    printLeafNodes(root);
    return 0;
}