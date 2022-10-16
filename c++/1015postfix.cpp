#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Converts string s to a int.
int string_to_double(const string& s) {
  return stoi(s);
}

string token;          // global variable
vector<string> stack;  // global variable
const string prompt = "--> ";

// remove and return the element of the stack
int pop() {
    if (stack.size() == 0) {
        cout << "tried to pop an empty stack"; // throws an exception
        return 0;  // never called: only needed to satisfy the compiler
    } else {
        int tos = stoi(stack.back());
        stack.pop_back();
        return tos;
    }
}

// put x on the top of the stack
void push(int x) {
    stack.push_back(std::to_string(x));
}

int main() {
    
    int i = 0;
    std::string token;
    string previousOp = "";
    bool test = false;


    while (getline(std::cin, token)) {
        if((previousOp == "+") | (previousOp == "*") | (previousOp == "-") | (previousOp == "/")){
        test = true;
        }
         else test = false;
        if (token == "+" & !test) {
            try {
                previousOp = token;
                int b = pop();
                int a = pop();
                push(a + b);
            } catch (runtime_error e) {
                cout << "Error: stack is empty\n";
                cout << prompt;
            }
        } else if (token == "-" & !test) {
            try {
                previousOp = token;
                int b = pop();
                int a = pop();
                push(a - b);
            } catch (runtime_error e) {
                cout << "Error: stack is empty\n";
                cout << prompt;
            }
        } else if (token == "*" & !test) {
            try {
                previousOp = token;
                int b = pop();
                int a = pop();
                push(a * b);
            } catch (runtime_error e) {
                cout << "Error: stack is empty\n";
                cout << prompt;
            }
        } else if (token == "/" & !test) {
            try {
                previousOp = token;
                int b = pop();
                int a = pop();
                push(a / b);
            } catch (runtime_error e) {
                cout << "Error: stack is empty\n";
                cout << prompt;
            }
        } else if (token.empty()) {
                break;
        }
        else if(((token == "+") | (token == "*") | (token == "-") | (token == "/")) & test){
                push(-100);
                break;
        }
         else {
            previousOp = token;
            push(string_to_double(token));
        }
        i++;
    }
    string last = stack.back();
    cout << last << "\n";
    return 0;
}