#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
Node* newNode(int data);
int search(int arr[], int strt, int end, int value);

Node* buildUtil(int in[], int post[], int inStrt,
                int inEnd, int* pIndex)
{
    if (inStrt > inEnd)
        return NULL;
    Node* node = newNode(post[*pIndex]);
    (*pIndex)--;
    if (inStrt == inEnd)
        return node;
    int iIndex = search(in, inStrt, inEnd, node->data);
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
 
    return node;
}

Node* buildTree(int in[], int post[], int n)
{
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}


int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}
 
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int n = 0;
vector<int> getInput() {
  int c;
  vector<int> cl;
  std::string line;
  std::getline(cin, line);
  std::istringstream iss(line);
  while ( iss >> c) {    
    cl.push_back(c);
    n++;
  }
  return cl;
}
 

int main()
{
    vector<int> postorder = getInput();
    vector<int> inorder = getInput();
    int numElements =  n/2;
    //3<=n<=10
    if(numElements<3 || numElements>10){
        cout << "Invalid input";
        return 0;
    }
    int* pos = postorder.data();;
    int* ino = inorder.data();;
    Node* root = buildTree(ino, pos, numElements);
    preOrder(root);
    
    return 0;
}