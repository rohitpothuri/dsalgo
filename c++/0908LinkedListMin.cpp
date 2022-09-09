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
    
    int smallestElement(struct Node* head)
    {
    int min = INT_MAX;
    // Check loop while head not equal to NULL
    while (head != NULL) {
        if (min > head->data)
            min = head->data;
 
        head = head->next;
    }
    return min;
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
    cin.ignore();
    string str;
    getline(cin, str);

    int elements = count_spaces(str)+1;

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