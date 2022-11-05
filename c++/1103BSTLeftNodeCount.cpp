#include<iostream>
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

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        //int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        lDepth = lDepth + 1 ;
        return lDepth;
    }
} 


int main()
{
    struct node* root = NULL;
    int n,d;
    cin>>n;
    if(n< 3 || n>12)
    {
        cout<<"Enter correct range";
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
 
    cout << maxDepth(root);
 
    return 0;
}     
