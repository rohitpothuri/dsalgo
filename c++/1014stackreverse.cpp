#include <cstdio>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;

class Stack {
public:
	int top;
	int capacity;
	char* array;
};

Stack* createStack(int capacity)
{
	Stack* stack = new Stack();
	stack->capacity = capacity;
	stack->top = -1;
	stack->array
		= new char[(stack->capacity * sizeof(char))];
	return stack;
}

int isFull(Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, char item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
}

char pop(Stack* stack)
{
	if (isEmpty(stack))
		return -1;
	return stack->array[stack->top--];
}

void reverse(char str[])
{
	int n = strlen(str);

    if(n<5 || n>30){
        cout << "Maximum size of string is 30 and minimum size is 5";
        return;
    }
	Stack* stack = createStack(n);
	int i;
	for (i = 0; i < n; i++)
		push(stack, str[i]);
	for (i = 0; i < n; i++)
		str[i] = pop(stack);
}

int main()
{

	char str[0] = "";
    cin.getline(str,30);
	reverse(str);
	cout<< str;
	return 0;
}
