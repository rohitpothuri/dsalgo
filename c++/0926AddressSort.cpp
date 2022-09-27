#include <iostream>
#include <ctype.h>
#include <sstream>
#include <climits>
using namespace std;

struct Node {
	string name;
    int strength;
	struct Node* next;
	Node(string val1, int val2)
	{
		name = val1;
        strength = val2;
		next = NULL;
	}
};

class LinkedlistIS {

public:
	Node* head;
	Node* sorted;

	void push(string val1, int val2)
	{
		Node* newnode = new Node(val1, val2);
		newnode->next = head;
		head = newnode;
	}
    void append (string val1, int val2)
    {
        Node* newnode = new Node(val1, val2);
        Node *last = head;
        newnode->name = val1;
        newnode->strength = val2;
        newnode->next = NULL;
        if (head == NULL)
            {
            head = newnode;
            return;
            }
        while (last->next != NULL)
            {
            last = last->next;
            }
        last->next = newnode;
        return;
    }



	void insertionSort(Node* headref)
	{
		sorted = NULL;
		Node* current = headref;
		while (current != NULL) {
			Node* next = current->next;
			sortedInsert(current);
			current = next;
		}
		head = sorted;
	}

	void sortedInsert(Node* newnode)
	{
		if (sorted == NULL || sorted->strength <= newnode->strength) {
			newnode->next = sorted;
			sorted = newnode;
		}
		else {
			Node* current = sorted;
			while (current->next != NULL
				&& current->next->strength > newnode->strength) {
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}
	void printlist(Node* head)
	{
		while (head != NULL) {
			cout << head->name << " ";
			head = head->next;
		}
        cout << endl;
	}
};
int main()
{
	LinkedlistIS list;
	list.head = NULL;
    int N;
    cin >> N;
    cin.ignore();
    if(N<=4 || N>=9){
        cout << "Invalid Input";
        return 0;
    }
    int prevNumber = INT_MAX;
    string lastName;
    int lastStrength;

    for (int i = 0; i < N+1; ++i) {
        std::string s;
        int a;
        std::cin >> s >> a;
        if(i<N){
            if(a>prevNumber){
                cout << "Invalid Input";
                return 0;
            }
          list.append(s,a);  
        }
        else if(i==N){
            lastName = s;
            lastStrength = a;
        }
        prevNumber = a;
    }
    list.printlist(list.head);
    list.append(lastName,lastStrength);
    list.insertionSort(list.head);
	list.printlist(list.head);
	
}
