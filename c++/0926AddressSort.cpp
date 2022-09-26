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

    for (int i = 0; i < N+1; ++i) {
        std::string s;
        int a;
        std::cin >> s >> a;
        if(i<N){
            if(a>prevNumber){
                cout << "Invalid Input";
                return 0;
            }
        }
        list.push(s,a);
        prevNumber = a;
    }
    list.printlist(list.head);
    list.insertionSort(list.head);
	list.printlist(list.head);
	
}
