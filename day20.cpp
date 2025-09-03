/*
  Question :- 
  Given a stack of integers, your task is to write a function that sorts the stack in ascending order. 
  You are not allowed to use any additional data structure like arrays, lists, or another stack. 
  The only operations you are allowed to perform are push, pop, and peek on the stack. The sorting must be performed using recursion only.

You need to recursively sort the stack, ensuring that after the sorting process, the stack remains sorted without using any additional data structures. 
You can only use the stack's own operations and recursion to solve this problem.

*/

// Code :- 
#include<iostream>
#include<stack>
using namespace std;
void insertionInStack(stack<int> &s,int x)
{
    if(s.empty() || x>s.top())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertionInStack(s,x);
    s.push(temp);
}
void sortStack(stack<int> &s)
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        sortStack(s);
        insertionInStack(s,x);
    }
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    sortStack(s);
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
