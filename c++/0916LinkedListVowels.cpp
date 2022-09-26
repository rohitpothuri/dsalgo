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

Node* getNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertPos(Node** current, int pos, char data, int size)
{
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
        while (pos--) {
  
            if (pos == 0) {
                Node* temp = getNode(data);
                temp->next = *current;
                *current = temp;
            }
            else
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

int checkAdjacentVowels(Node** head,int numElements ){
  Node* current = *head;
  int counter = 0;
  while (counter < numElements-1){

    char cur =  current->data;
    Node *next = current->next;
    char nextVal = next->data;

    if(isVowel(cur) && isVowel(nextVal)){
      return -1;
    }
    current = current->next;
    counter ++;
  }
  return 0;

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
      return 0;
      break;
      
    }
  }
  char y;
  cin >> y;
  if (!isupper(y)){
    cout << "Input should be upper case";
    return 0;
  }
  int c = checkAdjacentVowels(&head, N);
  if(c==-1){
    cout << "Wrong input";
    return 0;
  }


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