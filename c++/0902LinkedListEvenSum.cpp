#include <iostream>
#include <ctype.h>
#include <sstream>
using namespace std;

struct node
{
    int data;
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

    void add_node(int n)
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

    node* gethead()
    {
        return head;
    }
    
    static void sumEven(node *head)
    {
        int sum=-1;
        while(head!=NULL)
        {
             if((head->data)%2==0){
              if(sum==-1){
                sum=0;
              }
                sum = sum+(head->data);
            }
            head= head->next;
        }
        if(sum == -1)
            cout << "No Even numbers Present";
        else
            cout << sum;
    }
};

int count_spaces(string s) {
  int count = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ') count++;

  return count;
}

int main()
{
    int n;
    cin >> n;
    if(n<0){
      cout << "Value of N Must be Positive and Greater than 0";
    }
    cin.ignore();
    string str;
    getline(cin, str);

    int elements = count_spaces(str)+1;

    if(n!=elements){
      cout << "No of elements and input doesnt match";
    }

    linked_list a;
    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < n){
        int x;
        ssin >> x;
        if(x==-1)
            break;
        else if(x>-1)    
            a.add_node(x);
        
        ++i;
    }
    linked_list::sumEven(a.gethead());
    return 0;
}