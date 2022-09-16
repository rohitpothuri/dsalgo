#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;

struct Node
{
  char data;
  struct Node *next;
};

void
append (Node ** head_ref, char new_data)
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
deleteNode (struct Node **head_ref, char key)
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

static int deleteVowels (Node ** head_ref)
  {
     Node *ptr = *head_ref;
     int counter = 0;
    while (ptr != NULL)
      {
        char value = ptr->data;
        if (value == 'a' || value=='e' || value=='i' || value=='o' || value=='u' ){
          deleteNode (head_ref, value);
          counter ++;

        }
        ptr = ptr->next;
      }
      return counter;
  }

void
printList (Node *node)
{
  while (node != NULL)
    {
      cout << node->data;
      node = node->next;
      if(node != NULL){
        cout << "-->";
      }
    }
  //cout << endl;
}

int
main ()
{
  Node *head = NULL;
  string line;
  while (getline(cin, line))
  {
    append(&head, line[0]);
  }
  int doVowelsExist = deleteVowels(&head);
  if(doVowelsExist==0){
    cout << "No vowel in linked list";
  }

  else{
    printList (head);
  }
  return 0;
}