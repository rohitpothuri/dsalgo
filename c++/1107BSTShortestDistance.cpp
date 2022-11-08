// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert
a new node with given key in
* BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

int distanceFromRoot(struct node* root, int x)
{
    if (root->key == x)
        return 0;
    else if (root->key > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct node* root, int a, int b)
{
    if (!root)
        return 0;
    else if (root->key > a && root->key > b)
        return distanceBetween2(root->left, a, b);
    else if (root->key < a && root->key < b)
        return distanceBetween2(root->right, a, b);
    else if (root->key >= a && root->key <= b)
        return distanceFromRoot(root, a) +
               distanceFromRoot(root, b);
    else
        return 0;           
}

int findDistWrapper(node *root, int a, int b)
{
   //if (a > b)
     //swap(a, b);
   return distanceBetween2(root, a, b);  
}

// Driver Code
int main()
{
    int n=0;
    scanf ("%d", &n);
	struct node* root = NULL;
    if(n>=5 && n<20){
        for(int i = 0;i < n;i++){
            int k = 0;
            scanf ("%d", &k);
            if(i==0){
                root = insert(root, k);
            }
            else{
                insert(root, k);
            }
        }
        int a, b = 0;
        scanf ("%d", &a);
        scanf ("%d", &b);
        printf("%d",findDistWrapper(root, a, b));
      
    }
    else{
        return 0;
    }

	// print inoder traversal of the BST

	return 0;
}
