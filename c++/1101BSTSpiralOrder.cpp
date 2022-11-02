#include<iostream>
#include <vector>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);
 
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;
    bool ltr = false;
    for (i = 1; i <= h; i++) {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}

void printGivenLevel(struct node* root, int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
 
    else if (level > 1) {
        if (ltr) {
            printGivenLevel(root->left, level - 1, ltr);
            printGivenLevel(root->right, level - 1, ltr);
        }
        else {
            printGivenLevel(root->right, level - 1, ltr);
            printGivenLevel(root->left, level - 1, ltr);
        }
    }
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
 
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

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

 
// Driver code
int main()
{
    struct node* root = NULL;
    //7 1 3 5 7 9 11 13
    int n,d;
    cin>>n;
    if(n<= 0)
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
    
    printf("Spiral Order traversal of binary tree: ");
 
    printSpiral(root);
 
    return 0;
}     