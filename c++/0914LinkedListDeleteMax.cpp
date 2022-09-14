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

static void deleteLargestElement (Node ** head_ref)
  {
     Node *ptr = *head_ref;
    int max = INT_MIN;
    while (ptr != NULL)
      {
        if (max < ptr->data)
          max = ptr->data;
        ptr = ptr->next;
      }
    deleteNode (head_ref, max);
  }

void
printList (Node *node)
{
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int countDuplicateEmps (Node * head)
  {
    int count = 0;

    while (head != NULL)
      {
	Node *current = head->next;
	while (current != NULL)
	  {
	    if (head->data == current->data)
	      {
		count++;	// increase the count of duplicate nodes.
		break;
	      }
	    current = current->next;
	  }
	head = head->next;
      }
    return count;
  }

int
main ()
{

  int n;
  cin >> n;
  if(n<0){
    cout << "Number should be positive";
    return 0;
  }
  cin.ignore();
  string str;
  getline (cin, str);

  int elements = count_spaces (str) + 1;
  Node *head = NULL;

  int i = 0;
  stringstream ssin (str);

  while (ssin.good () && i < n)
    {
      string x;
      ssin >> x;
      int number;
      try
      {
        number = std::stoi (x);
        if(number<0){
          cout << "Number should be positive";
          return 0;
          break;
        }
        append (&head, number);
      }
      catch (std::exception & e)
      {
	      //do nothing
      }
      ++i;
    }

  int dups = countDuplicateEmps(head) ;
  if(dups>0){
    cout << "Cannot have duplicates";
    return 0;
  }
  else{
    deleteLargestElement(&head);
    printList (head);
  }
  
  
  return 0;

}
