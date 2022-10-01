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

void DisplayEvens(struct Node* head, int size)
{
	struct Node* current = head;
	int currentLoop = 1;
	for(int i=0; i<size; i++){

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
}

int main()
{
  int N;
  cin >> N;
  if(N!=5){
    cout << "Value should be 5";
    return 0;
  }

  cin.ignore();
  string str;
  getline (cin, str);
  Node *head = NULL;

  int i = 0;
  stringstream ssin (str);
  int oddExists = -1;
  int evenExists = -1;
  while (ssin.good () && i < N)
    {
      int x;
      ssin >> x;
	  if(x%2==0){
		evenExists++;
	  }
	  else{
		oddExists++;
	  }
      Insert (&head, x);
      ++i;
    }
	if(oddExists==-1 || evenExists ==-1){
		cout << "There should be at least one odd and even integer value in the list";
		return 0;
	}


	//DeleteAtIndex(&head, N);
	Display(head);
	return 0;
}
