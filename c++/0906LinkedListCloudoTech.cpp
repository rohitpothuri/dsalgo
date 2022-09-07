#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Employee
{
    string emp_name;

    int salary;
    int emp_id;
    Employee *next;
};

Employee *Cloudo_Tech = NULL;
Employee *head = NULL;

void add_employee()
{
   //Creating Employee 
  
    Employee *emp = new Employee;
    cin>>emp->emp_name;
    cin>>emp->emp_id;
    cin>>emp->salary;
  
  //Inserting Employee in the beginning of the list
  
    emp->next = Cloudo_Tech;
    Cloudo_Tech = emp;
    
}

void search_employee(int emp_id)
{
    int counter = 0;

    while (Cloudo_Tech != NULL) {
        if (Cloudo_Tech->emp_id == emp_id){
            cout<< Cloudo_Tech->emp_name << " " << Cloudo_Tech->salary;
            counter = counter + 1;
        }
            
        Cloudo_Tech = Cloudo_Tech->next;

        if(counter==0){
            cout << "Employee does not exist";
        }
    }

}

int countDuplicateEmps()
{
    int count = 0;

    while (Cloudo_Tech->next != NULL) {

        // Starting from the next node.
        Employee *current = Cloudo_Tech->next;
        while (current != NULL) {

            // If some duplicate node is found.
            if (Cloudo_Tech->emp_id == current->emp_id) {
                count++; // increase the count of duplicate nodes.
                break;
            }
            current = current->next;
        }

        Cloudo_Tech = Cloudo_Tech->next;
    }

    // Return the count of duplicate nodes.
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     
    int n;
    cin>>n;     //Reading number of employees

    if(n<1){
        cout << "Number of employees should be greater than 0";
        return 0;
    }
  
    for(int i=0; i<n; i++)        //adding employees in the list
      add_employee();
    
    int empId;
    cin>>empId; 


    if(countDuplicateEmps()>0){
        cout << "Duplicate empIds not allowed";
        return 0;
    }
    
    search_employee(empId);

  
    return 0;
}