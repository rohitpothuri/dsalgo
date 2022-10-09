#include <iostream>
#include <stack>
using namespace std;

std::stack<std::string> stk;
int num;
void push ()
{
      cin >> num;
      if(num < 1){
            cout << "Invalid input\n";
            return;
      }

      for(int i=0; i<num; i++){
            string s;
            cin >> s;
            stk.push(s);
      }
      return;
}

void display ()
{     
      std::stack<std::string> tempstk;
      if(stk.empty()){
            cout << "Its empty" << endl;
            return;
      }

      string topV = stk.top();
      cout << topV << endl;    
      stk.pop();
      int  stacksize = stk.size();

      /* for(int i=0; i<stacksize; i++){
            tempstk.push(stk.top());
            stk.pop();
      } */

      for(int i=0; i<stacksize; i++){
            cout << stk.top() << endl;
            stk.pop();
      }
      
}
int main ()
{
      int ch;
      while(1)
      {
            cin >> ch;
            switch (ch)
            {
                  case 1:
                        push();
                        break;
                  case 2:
                        display();
                        exit(0);
                  default: 
                        printf("Invalid operation \n");
            }
      }
      return 0;
}