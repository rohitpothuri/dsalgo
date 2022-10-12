#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
	int rear, front;
	int size;
	string *arr;
public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new string[s];
	}

	void enQueue(string value);
	void deQueue();
	void displayQueue();
};

void Queue::enQueue(string value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		printf("\nOVERFLOW");
		return;
	}

	else if (front == -1)
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

void Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}

	string data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return;
}

void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}

    cout << arr[front] << endl;
    cout << arr[rear] << endl;
    return;
}

int main()
{
	Queue q(7);

    int ch;
      while(1)
      {
            cin >> ch;
            switch (ch)
            {
                  case 1:{
                    string ip;
                    cin >> ip;
                    q.enQueue(ip);
                    break;

                  }
                  case 2:{
                    q.deQueue();
                    break;
                  }
                  default: {
                    q.displayQueue();
                    exit(0);
                  }
            }
      }
      return 0;
}
