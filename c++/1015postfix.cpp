#include<bits/stdc++.h>
using namespace std;

bool val(string a){
    int n = a.length(), br = 0;
    for(int i = 0; i < n; i++){
        if(isdigit(a[i])){
            br++;
        }
        else{
            br -= 2;
            if(br < 0){
                return false;
            }
            br++;
        }
    }
    if(br == 1)
        return true;
    return false;
}

int main(){
    string q;
    stack<int> h;
    for(int i=0;i<100;i++){
        string b;
        cin >> b;
        q.append(b);
    }
    if(val(q)){
        for(int i=0; i < q.length(); i++){

            if (isdigit(q[i]))
                h.push(q[i] - '0');

            else{
                int op2=h.top();
                h.pop();
                int op1=h.top();
                h.pop();

                if(q[i] == '+')
                    h.push(op1 + op2);
                else if(q[i] == '-')
                    h.push(op1 - op2);
                else if(q[i] == '*')
                    h.push(op1 * op2);
                else if(q[i] == '/')
                    h.push(op1 / op2);
            }
        }
        cout << h.top();
    }
    else{
        cout<<"Invalid Input";
    }
    return 0;
}