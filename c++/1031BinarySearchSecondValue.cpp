#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count = 0;
class node
{
public:
    int data;
    node* left= NULL;
    node* right = NULL;
    node(int d)
    {
        this->data = d;
    }
};
node*root = NULL;
void insert(int d)
{
    node *new_node = new node(d);
    if(root == NULL)
    {
        root = new_node;
    }else
    {
        node *ptr = root;
        node *parent = NULL;
        while(ptr)
        {
            if(ptr->data > d)
            {            parent = ptr;
                ptr = ptr->left;
            }
            else
            {
                parent = ptr;
                ptr = ptr->right;
            }
        }
        if(parent->data > d)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }
}

void inorder(node *ptr)
{
    cout<<ptr->data;
}
int main() 
{
    int n,d;
    cin>>n;
    if(n<= 2 || n>10)
    {
        cout<<"Invalid Size";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insert(d);
    }
    inorder(root);
    return 0;
}