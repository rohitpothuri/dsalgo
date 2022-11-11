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

struct node* constructTreeUtil(int post[], int* postIndex,
                               int key, int min, int max,
                               int size)
{
    if (*postIndex < 0)
        return NULL;
 
    struct node* root = NULL;
    if (key > min && key < max)
    {
        root = newNode(key);
        *postIndex = *postIndex - 1;
 
        if (*postIndex >= 0)
        {
        root->right = constructTreeUtil(post, postIndex,
                                        post[*postIndex],
                                        key, max, size );

        root->left = constructTreeUtil(post, postIndex,
                                       post[*postIndex],
                                       min, key, size );
        }
    }
    return root;
}

struct node *constructTree (int post[],
                            int size)
{
    int postIndex = size-1;
    return constructTreeUtil(post, &postIndex,
                             post[postIndex],
                             INT_MIN, INT_MAX, size);
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