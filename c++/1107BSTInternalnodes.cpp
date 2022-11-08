#include<iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node{
    int info;
    struct node *left,*right;
};
vector<int> qs;

struct node *root = NULL;

void insertion(){
    struct node *n = new node,*ptr = root,*par = NULL;
    cin>>n->info;
    n->left = NULL;
    n->right = NULL;
    if(root == NULL){
        root = n;
        return;
    }
    while(ptr != NULL){
        par = ptr;
        if(n->info < ptr->info){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    if(par->info > n->info){
        par->left = n;
    }
    else{
        par->right = n;
    }
}

void printInternalNodes(node* root)
{
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        bool isInternal = 0;
        if (curr->left) {
            isInternal = 1;
            q.push(curr->left);
        }
        if (curr->right) {
            isInternal = 1;
            q.push(curr->right);
        }
        if (isInternal){
          int j = curr->info;
          qs.push_back(j);
        }  
    }
}

int main(){
    int n= 0;
    cin>>n;
    if(n>0){
        for(int i = 0;i < n;i++){
            insertion();
        }
      printInternalNodes(root);
      sort(qs.begin(), qs.end());
      for (auto x : qs)
        cout << x << " ";
    }
    else{
        cout<<"Enter correct range";
    }
    return 0;
}