#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
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

void
append (Node ** head_ref, int new_data)
{
  Node *new_node = new Node ();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL)
    {
      *head_ref = new_node;
      return;
    }
  while (last->next != NULL)
    {
      last = last->next;
    }
  last->next = new_node;
  return;
}

void
deleteNode (struct Node **head_ref, int key)
{

  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key)
    {
      *head_ref = temp->next;
      return;
    }

  while (temp != NULL && temp->data != key)
    {
      prev = temp;
      temp = temp->next;
    }

  if (temp == NULL)
    return;

  prev->next = temp->next;


}

int
deleteEvenNodes (Node ** head_ref)
{

int isEvenPresent = -1;
  Node *ptr = *head_ref;
  while (ptr != NULL)
    {
      if (ptr->data % 2 == 0){
        isEvenPresent = 1;
        deleteNode (head_ref, ptr->data);
      }
      ptr = ptr->next;
    }
  return isEvenPresent;
}

void
printList (struct Node *node)
{
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int
main ()
{
  string str;
  getline (cin, str);

  int elements = count_spaces (str) + 1;
  Node *head = NULL;

  int i = 0;
  stringstream ssin (str);

  while (ssin.good () && i < elements)
    {
      string x;
      ssin >> x;
      int number;
      try
      {
        number = std::stoi (x);
        if(number==-1)
            break;
        else if(number>-1)    
             append (&head, number);
      }
      catch (std::exception & e)
      {
	      //do nothing
      }
      ++i;
    }

  if(head == NULL){
    cout << "Linked list should not be empty";
    return 0;
  }  
  if(deleteEvenNodes(&head)==1){
    printList (head);
  }
  else{
    cout << "No odd number present";
  }
  return 0;

}
