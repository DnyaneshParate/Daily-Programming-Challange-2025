/*
  Question :- 
  You are given a stack of integers, and your task is to write a function that reverses the stack using recursion. 
  You are not allowed to use any additional data structure (like arrays, lists, or another stack).
  The only operations you are allowed to perform are push, pop, and peek on the stack. The reversal must be done using recursion only. 
*/

// Code :- 
#include <iostream>
#include <stack>
using namespace std;

// Insert element at the bottom of stack
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

// Reverse stack using recursion
void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, topElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
