#include <stdio.h>
#include <stdlib.h>

struct SLLNode
{
  int data;
  struct SLLNode *next;
};

void
append (struct SLLNode **head_ref, int new_data)
{
  struct SLLNode *new_node =
    (struct SLLNode *) malloc (sizeof (struct SLLNode));
  struct SLLNode *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL)
    {
      *head_ref = new_node;
      return;
    }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

void
printList (struct SLLNode *node)
{
  if (node == NULL)
    {
      printf ("%s", "SLL is Empty");
    }
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
}

void
deleteNode (struct SLLNode **head, int position)
{
  struct SLLNode *temp;
  struct SLLNode *prev;
  temp = *head;
  prev = *head;
  for (int i = 0; i < position; i++)
    {
      if (i == 0 && position == 1)
	{
	  *head = (*head)->next;
	  free (temp);
	}
      else
	{
	  if (i == position - 1 && temp)
	    {
	      prev->next = temp->next;
	      free (temp);
	    }
	  else
	    {
	      prev = temp;
	      if (prev == NULL)
		break;
	      temp = temp->next;
	    }
	}
    }
}

int
main ()
{

  int size = 0;
  scanf ("%d", &size);

  if (size < 0 || size > 1000)
    {
      printf ("%s", "Invalid Size");
      return 0;
    }

  struct SLLNode *head = NULL;

  int i;
  int *v;
  v = malloc (size * sizeof (int));
  for (i = 0; i < size; i++)
    {
      scanf ("%d", &v[i]);
      if (v[i] < 0 || v[i] > 1000)
	{
	  printf ("%s", "Invalid Element");
	  return 0;
	}
      append (&head, v[i]);
    }
  int delIndex = 0;
  scanf ("%d", &delIndex);
  if (delIndex < 0 || delIndex >= size)
    {
      printf ("%s", "Invalid Position");
      return 0;
    }
  deleteNode (&head, delIndex + 1);
  printList (head);
  return 0;
}
