#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node
{
  char data;
  struct Node *next;
};

// function to create and return a Node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();
  
    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertPos(Node** current, int pos, char data, int size)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
  
        // Keep looping until the pos is zero
        while (pos--) {
  
            if (pos == 0) {
  
                // adding Node at required position
                Node* temp = getNode(data);
  
                // Making the new Node to point to 
                // the old Node at the same position
                temp->next = *current;
  
                // Changing the pointer of the Node previous 
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the 
              // pointer pointing to the address of next Node 
              current = &(*current)->next;
        }
        size++;
    }
}



bool isVowel(char v){
   switch(v){
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      return true;
      default:
      return false;
   }
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

int insertVowel(Node** head, int numElements, char data){

  int isInserted = 0;
  int counter = 0;
  Node* current = *head;
  while (counter < numElements-1){
    char cur =  current->data;
    Node *next = current->next;
    char nextVal = next->data;
    
    if((counter == 1 || counter ==numElements) && !isVowel(cur)){
      insertPos(head, counter+1, data, numElements);
      isInserted = 1;
      break;
    }
    else if(!isVowel(cur) && !isVowel(nextVal)){
      isInserted = 1;
      insertPos(head, counter+1, data, numElements);
      break;
    }
    else{
      isInserted = 0;
      cout << "Can't be inserted";
      break;
    }
    counter ++;
    current = current->next;
  }
  return isInserted;
}


int insertConsonant(Node** head, int numElements, char data){

  int isInserted = 0;
  int counter = 0;
  Node* current = *head;
  while (counter < numElements-1){
    char cur =  current->data;
    Node *next = current->next;
    char nextVal = next->data;
    
    if(isVowel(cur) || isVowel(nextVal)){
      insertPos(head, counter+1, data, numElements);
      isInserted = 1;
      break;
    }
    else{
      isInserted = 0;
      cout << "Can't be inserted";
      break;
    }
    counter ++;
    current = current->next;
  }
  return isInserted;
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
  int N;
  cin >> N;

  Node *head = NULL;
  for(int i=0; i< N; i++){
    char x;
    cin >> x;
    if (isupper(x)){
      append (&head, x);
    }
    else{
      cout << "All characters in the node should be upper cased";
      break;
      return 0;
    }
  }
  char y;
  cin >> y;
  int z = -1;
  if(isVowel(y)){
    z = insertVowel(&head, N, y);
  }
  else{
    z = insertConsonant(&head, N, y);
  }
  
  if(z == 1){
    printList (head);
  }
  return 0;

}
