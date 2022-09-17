#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void Insert(struct Node** head, int data)
{
	struct Node* current = *head;
	struct Node* newNode = new Node;
	if (!newNode) {
		printf("New node issue");
		return;
	}
	newNode->data = data;
	if (*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return;
	}
	else {
		while (current->next != *head) {
			current = current->next;
		}
		newNode->next = *head;
		current->next = newNode;
	}
}

void Display(struct Node* head)
{
	struct Node* current = head;
	if (head == NULL) {
		printf("List is empty");
		return;
	}
		do {
			cout << current->data << " ";
			current = current->next;
		} while (current != head);

    cout << endl;
}

int Length(struct Node* head)
{
	struct Node* current = head;
	int count = 0;
	if (head == NULL) {
		return 0;
	}
	else {
		do {
			current = current->next;
			count++;
		} while (current != head);
	}
	return count;
}

void DeleteFirst(struct Node** head)
{
    struct Node *previous = *head, *next = *head;
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if (previous->next == previous) {
        *head = NULL;
        return;
    }
    while (previous->next != *head) {
 
        previous = previous->next;
        next = previous->next;
    }
    previous->next = next->next;
    *head = previous->next;
    free(next);
    return;
}

void DeleteAtIndex(struct Node** head, int index)
{
	int len = Length(*head);
	int count = 1;
	struct Node *previous = *head, *next = *head;
	if (*head == NULL) {
		cout << "Delete Last List is empty";
		return;
	}
	if (index >= len || index < 0) {
		cout << "Index is not Found";
		return;
	}

	if (index == 0) {
		DeleteFirst(head);
		return;
	}
	while (len > 0) {
		if (index == count) {
			previous->next = next->next;
			free(next);
			return;
		}
		previous = previous->next;
		next = previous->next;
		len--;
		count++;
	}
	return;
}

int main()
{
  int N;
  cin >> N;
  if(N<0){
    cout << "Value should not be negative";
    return 0;
  }
  //2 5 7 8 9 10 12

  int numElements;
  cin >> numElements;
  if(numElements<1 || numElements>49){
    cout << "Value should between 1 and 49";
    return 0;
  }

  
  cin.ignore();
  string str;
  getline (cin, str);

  Node *head = NULL;

  int i = 0;
  stringstream ssin (str);

  while (ssin.good () && i < numElements)
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
        Insert (&head, number);
      }
      catch (std::exception & e)
      {
	      //do nothing
      }
      ++i;
    }
	DeleteAtIndex(&head, N);
	Display(head);
	return 0;
}
