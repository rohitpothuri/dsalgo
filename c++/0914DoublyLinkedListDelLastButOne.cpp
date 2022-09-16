#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
};

void reverse(struct Node** head_ref)
{
 struct Node* temp = NULL;
 struct Node* current = *head_ref;
 while (current != NULL) {
  temp = current->prev;
  current->prev = current->next;
  current->next = temp;
  current = current->prev;
 }
 if (temp != NULL)
  *head_ref = temp->prev;
}

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

int deleteLastButOne(Node** head_ref, int valueToDelete)
{
    Node* ptr = *head_ref;
    Node* next;
    int counter = 0;
    while (ptr != NULL) {
        next = ptr->next;

        if (ptr->data == valueToDelete && counter==1){
           deleteNode(head_ref, ptr);
           counter++;
           break;
        }
        else if(ptr->data == valueToDelete){
          counter++;
        }
        ptr = next;
    }
   return counter;
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
  printf("%d\n", node->data);
  node = node->next;
 }
}

int main()
{
  int n = 0;
  scanf("%d", &n);

  if(n<=2 || n>20){
    printf("%s","Invalid list size");
    return 0;
  }

  struct Node* head = NULL;
  for (int i = 0; i < n; i++)
    {
      int x = 0;
      scanf("%d", &x);
      append (&head, x);
    }
  int valueToDelete = -1;
  scanf("%d", &valueToDelete);  

  reverse(&head);
  int g = deleteLastButOne(&head, valueToDelete);
  if(g<2){
      printf("%s","Deletion not possible");
  }
  else{
     printList(head);
  }
  return 0;
}

