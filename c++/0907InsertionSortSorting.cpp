#include <iostream>
#include <ctype.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    string data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(string n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    static string reverseStr(string str)
    {
        int len = str.length();
        int n = len-1;
        int i = 0;
        while(i<=n){
            swap(str[i],str[n]);
            n = n-1;
            i = i+1;
        }
        return str;
 
    }

    node* gethead()
    {
        return head;
    }
    
    static void checkPalindrome(node *head, int numElements)
    {
        string z;
        while(head!=NULL)
        {
            
            z=z + string (head->data);
            head= head->next;
        }
        if(z==reverseStr(z)){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        
    }
};

int main()
{
    int n;
    cin >> n;
    if(n<5 || n>=15){
      cout << "Invalid Input";
      return 0;
    }
    linked_list a;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        a.add_node(x);

    }
    linked_list::checkPalindrome(a.gethead(),n);
    return 0;
}