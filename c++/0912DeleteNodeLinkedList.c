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
  printf("%d ", node->data);
  node = node->next;
 }
}

int main()
{
  int n = 0;
  scanf("%d", &n);

  int N = 0;
  scanf("%d", &N);

  struct Node* head = NULL;
  for (int i = 0; i < N; i++)
    {
      int x = 0;
      scanf("%d", &x);
      append (&head, x);

    }

 reverse(&head);
 printList(head);
 return 0;
}

