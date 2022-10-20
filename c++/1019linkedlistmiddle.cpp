#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
};

class NodeOperation {
public:
    void pushNode(class Node** head_ref, string data_val)
    {
        class Node* new_node = new Node();
        new_node->data = data_val;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }

    void printNode(class Node* head)
    {
        while (head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    int getLen(class Node* head)
    {
        int len = 0;
        class Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void printMiddle(class Node* head)
    {

        if (head) {
            // find length
            int len = getLen(head);
            class Node* temp = head;
            int midIdx = len / 2;
            while (midIdx--) {
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
};

int main()
{
    class Node* head = NULL;
    class NodeOperation* temp = new NodeOperation();

    int N;
    cin >> N;

    for(int i = 0; i< N; i++){
        string s;
        cin >> s;
        temp->pushNode(&head, s);

    }
    temp->printMiddle(head);
    return 0;
}
