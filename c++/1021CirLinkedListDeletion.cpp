#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }
 
    void push_back(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
        newNode->next = head;
      } else {
        Node* temp = head;
        while(temp->next != head)
          temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
      }    
    }

    void pop_front() {
      if(head != NULL) {
        if(head->next == head) {
          head = NULL;
        } else {
          Node* temp = head;
          Node* firstNode = head;
          while(temp->next != head) {
            temp = temp->next;
          }
          head = head->next;
          temp->next = head; 
          free(firstNode); 
        }
      }
      else{
        cout<<"Underflow";
        exit(0);
      }
    }

    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"CLL is Empty";
        return;
      }
    }     
};

int main() {
  LinkedList MyList;

  int n;
  cin >> n;

  if(n<0 || n>1000){
    cout << "Invalid Number";
    return 0;
  }

  for(int i=0; i<n; i++){
    int N;
    cin >> N;
    MyList.push_back(N);
  }
  MyList.pop_front();
  MyList.PrintList();  
  
  return 0; 
}