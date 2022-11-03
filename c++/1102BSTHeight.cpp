#include<iostream>
#include <vector>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}

struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}

int calculateHeight(node* node)
{
    if(node == NULL)
        {
            return -1;
        }
        else {
         int lh = calculateHeight(node->left) + 1;
         int rh = calculateHeight(node->right) + 1;
         return lh >= rh ? lh : rh;
         
        }
}


int main()
{
    struct node* root = NULL;
    int n,d;
    cin>>n;
    if(n< 3 || n>10)
    {
        cout<<"NOT IN RANGE";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>d;
        if(i==0){
            root = insertNode(root, d);
        }
        else{
            insertNode(root, d);
        }
    }
 
    cout << calculateHeight(root);
 
    return 0;
}     
