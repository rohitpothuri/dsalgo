#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
};


void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
 
    return;
}
 
int deleteEvenNodes(Node** head_ref)
{
    Node* ptr = *head_ref;
    Node* next;
    int oddExists = -1;
    while (ptr != NULL) {
        next = ptr->next;
        if (ptr->data % 2 != 0){
          oddExists = 1;
          deleteNode(head_ref, ptr);
        }         
        ptr = next;
    }
    return oddExists;
}

void append(struct Node** head_ref, int new_data)
{
 struct Node* new_node
  = (struct Node*)malloc(sizeof(struct Node));

 struct Node* last = *head_ref;
 new_node->data = new_data;
 new_node->next = NULL;
 if (*head_ref == NULL) {
  new_node->prev = NULL;
  *head_ref = new_node;
  return;
 }
 while (last->next != NULL)
  last = last->next;
 last->next = new_node;
 new_node->prev = last;
 return;
}

void printList(struct Node* node)
{
 while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
 }
 cout << endl;
}

int
main ()
{

  int n;
  cin >> n;

  if(n<3 || n >=12){
      cout << n << " Wrong Input";
      return 0;
  }

  Node* head = NULL;
  for (int z = 0; z < n; z++)
    {
      string N;
      cin >> N;
      try
      {
        int number;
        number = std::stoi (N);
        if(number==-1)
          break;
        else if(number>-1)    
          append(&head, number);
      }
      catch (std::exception & e)
      {
        //do nothing
      }
      
    }

  int rValue = deleteEvenNodes(&head);
  if(rValue==-1){
    cout << "No student is having odd roll number";
    return 0;
  }
  else{
    printList(head);
  }
  
  return 0;
}
