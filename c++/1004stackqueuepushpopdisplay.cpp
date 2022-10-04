#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
struct stack
{
      int stk[MAXSIZE];
      int top;
};
typedef struct stack ST;
ST s;

void push ()
{
      int num;
      if (s.top == (MAXSIZE - 1))
      {
            printf ("Stack is Full\n");
            return;
      }
      else
      {
            scanf ("%d", &num);
            s.top = s.top + 1;
            s.stk[s.top] = num;
      }
      return;
}
int pop ()
{
      int num;
      if (s.top == - 1)
      {
            printf ("-1");
            return (s.top);
      }
      else
      {
            num = s.stk[s.top];
            s.top = s.top - 1;
      }
      return(num);
}

void display ()
{
      int i;
      if (s.top == -1)
      {
            printf ("-1");
            return;
      }
      else
      {

        for (i = 0; i <= s.top; i++)
            {
                  printf ("%d\n", s.stk[i]);
            }
      }  
}
int main ()
{
      int ch;
      s.top = -1;
      while(1)
      {
            scanf("%d", &ch);
            switch (ch)
            {
                  case 1:
                        push();
                  break;
                  case 2:
                        pop();
                  break;
                  case 3:
                        display();
                        exit(0);
                  default: 
                        printf("Invalid operation \n");
            }
      }
      return 0;
}