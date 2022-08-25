### Data Structures and Algorithms
##### _08/24 playing cards_

```
Suppose You are having 13 playing cards of Heart and among these card you have to pick n cards in sorted order. Your task is to pick another card from the remaining and insert it in proper position of the previously sorted array
Example if you have picked 5 cards in sorted order 4 6 8 9 12 and then you pick next card 7 you have to insert the card 7 in its sorted position
Input Format
First line will be no of cards N second line will be the cards in sorted order you picked up Third line will be the card you want to insert
    Sample Input 1: 5 46 8 9 12 7
    Sample Output 1: 46 7 8 9 12
    Sample Input 2: 6 2 5 7 10 12 13 9
    Sample Output 2: 25 7 9 10 12 13
    Sample Input 3: 47 9 10 11 6
    Sample Output 3: 67 9 10 11
    Sample Input 4: 5 7 9 10 11 12 13
    Sample Output 4: 6 7 9 10 11 12 13
Constraints
Max size of the array is 13. value of N must greater than O and less than 13 All inputs are positive integers and inputs in the second line are non dupicate and in assending order
Output Format
Print the final array After inserting the card in proper position
Sample Input O
5
4 6 8 9 12
7
Sample Output 0
4 6 7 8 9 12
```

```
Consider a physical trainer is arranging the students for physical training in a school. There are N students
standing in a row for physical training. He wants to insert a student with average height between the two
students who are having odd height standing in consecutive. Write a program for a physical trainer so that he
can get the desired sequence of students.
Example: if the 5 students are having values: 3 6 5 9 7 then 5 and 9 are the students with odd height so the
student with height 7 (average of 5 and 9) should be inserted between 5 and 9. Similarly, 9 and 7 are the 2
students with odd heights so student with height 8 should be inserted between 9 and 7.
Output: 3 6 5 7 9 8 7
Input Format
The first line will be containing one Integer representing a number of students N. The second line will contain
N integers representing the heights of the students.
Constraints
N>2 && N<20
Output Format
The desired sequence of students after inserting students having the average height of two students with odd
height standing in consecutive in between them.
Sample Input 0
10
4 7 9 8 5 7 6 5 2 4
Sample Output 0
478985676524
Sample Input 1
Sample Output 1
Invalid Input
```
