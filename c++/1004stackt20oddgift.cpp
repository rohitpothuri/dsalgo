#include <iostream>
#include <stack>
using namespace std;

std::stack<std::string> stk;
int num;
int cnt = 0;
void push ()
{
      cin >> num;
      if(num <
      1){
            cout << "Invalid input\n";
            return;
      }

      for(int i=0; i<num; i++){
            if(cnt<=7){
                  string s;
                  cin >> s;
                  stk.push(s);
                  cnt ++;
            }
            else if(cnt == 8){
                  string s;
                  cin >> s;
                  stk.push(s);
                  cnt ++;
                  cout << "No other spectator is allowed" << endl;
            }
            else{
                  return;      
            }
      }
      return;
}

void display ()
{
      if(cnt == 0){
            cout << "queue is empty";
            return;
      }
      else if(cnt==1){
            cout << "No odd elements present";
            return;
      }
      else{
            int counter = 0;
            while (!stk.empty())
                  {     
                        if(counter%2!=0){
                        cout << stk.top();
                        }
                        counter ++;
                        stk.pop();
                  }
      }
      
}
int main ()
{
      int ch;
      cin >> ch;
      while(1)
      {
            switch (ch)
            {
                  case 1:
                        if(cnt<=8){
                              push();
                        }
                        else{
                            cout << "No other spectator is allowed\n";  
                        }
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