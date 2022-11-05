#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *left,*right;
};

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

void Inorder(struct node *p, int *cou){
    int count = *cou;
    if(p != NULL){
        Inorder(p->left, &count);
        count++;
        Inorder(p->right, &count);
    }
    *cou = count;
}

int main(){
    int n, c = 0;
    cin>>n;
    if(n>3 && n<=12){
        for(int i = 0;i < n;i++){
            insertion();
        }
        Inorder(root->left, &c);
        cout<<c;
    }
    else{
        cout<<"Enter correct range";
    }
    return 0;
}