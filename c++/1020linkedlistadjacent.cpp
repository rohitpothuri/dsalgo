#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data =x;
        next=NULL;
    }
};

Node *insert_end(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL) return temp;
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}
int* insertX(int n, int arr[],int x, int pos)
{
    int i;
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    return arr;
}

void print_list(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void print_list(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) break;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n,x,temp_sum,temp_index=0;
    int ins[3]={0,0,0};
    int ind[3]={0,0,0};
    cin>>n;
    int arr[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    if(n>5 && n<10)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[i]=x;
            head=insert_end(head,x);
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                temp_sum=arr[i-2]+arr[i+1];
                ins[temp_index]=temp_sum;
                ind[temp_index]=i+1;
                temp_index++;
            }
        }
        for(int i=0;i<3;i++)
        {
            if(ins[i]==0 || ind[i]==0) break;
            else
            {
                insertX(12,arr,ins[i],ind[i]);
                ind[1]++;
                ind[2]++;
            }
        }
        print_list(arr,12);
    }
    else
    {
        cout<<"Invalid Input";
    }
    return 0;
}