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
    
    static void countOdds(node *head)
    {
        int counter=0;
        while(head!=NULL)
        {
             if((head->data)%2!=0){
                counter = counter+1;
            }
            head= head->next;
        }
        if(counter == 0)
            cout << "No odd number present";
        else
            cout << counter;
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

    string str;
    getline(cin, str);
    linked_list a;

    int elements = count_spaces(str)+1;

    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < elements){
        int x;
        ssin >> x;
        if(x==-1)
            break;
        else if(x>-1)    
            a.add_node(x);
        
        ++i;
    }
    linked_list::countOdds(a.gethead());
    return 0;
}