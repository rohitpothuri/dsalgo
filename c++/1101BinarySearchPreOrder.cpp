#include<iostream>
#include <vector>
using namespace std;
std::vector< int > arr;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void preorder(struct node *root) {
   if (root != NULL) {
      arr.push_back(root->data);
      preorder(root->left);
      preorder(root->right);
   }
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
int main() {
   struct node *root = NULL;
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
        if(i==0){
            root = insertNode(root, d);
        }
        else{
            insertNode(root, d);
        }
    }
   preorder(root);
   cout << arr[1];
   return 0;
}