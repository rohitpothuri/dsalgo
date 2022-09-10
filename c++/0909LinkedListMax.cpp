#include <iostream>
#include <ctype.h>
#include <sstream>
#include <climits>
using namespace std;


struct node
{
  int data;
  node *next;
};

class linked_list
{
private:
  node * head, *tail;
public:
  linked_list ()
  {
    head = NULL;
    tail = NULL;
  }

  void add_node (int n)
  {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL)
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

  node *gethead ()
  {
    return head;
  }

  static void largestElement (node * head)
  {
    int max = INT_MIN;
    while (head != NULL)
      {
    if (max < head->data)
      max = head->data;

    head = head->next;
      }
    cout << max;
  }

  static int countDuplicateEmps (node * head)
  {
    int count = 0;

    while (head != NULL)
      {
    node *current = head->next;
    while (current != NULL)
      {
        if (head->data == current->data)
          {
        count++;    // increase the count of duplicate nodes.
        break;
          }
        current = current->next;
      }
    head = head->next;
      }
    return count;
  }


};

int
count_spaces (string s)
{
  int count = 0;
  int sz = s.size ();
  for (int i = 0; i < sz; i++)
    if (s[i] == ' ')
      count++;
  return count;
}

int
main ()
{
  string str;
  getline (cin, str);
  linked_list a;

  int elements = count_spaces (str) + 1;

  int i = 0;
  stringstream ssin (str);

  while (ssin.good () && i < elements)
    {
      string x;
      ssin >> x;
      int number;
      try{
        number = std::stoi(x); 
        a.add_node (number);
      }
      catch(std::exception& e){
        //do nothing
      }     
      ++i;
    }
  if (linked_list::countDuplicateEmps (a.gethead ()) > 0)
    {
      cout << "Cannot have duplicates";
      return 0;
    }
  linked_list::largestElement (a.gethead ());
  return 0;
}
