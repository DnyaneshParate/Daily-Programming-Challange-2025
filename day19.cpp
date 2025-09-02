/*
  Question :- 
  Given a postfix expression (also known as Reverse Polish Notation), your task is to evaluate the expression and return the result. 
  The expression can contain integers and the four basic arithmetic operators +, -, *, and /. Assume that the input is always valid and 
  the division operator performs integer division, truncating towards zero.

*/



// Code :- 
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int calc(int left, char op, int right)
{
    switch (op)
    {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/':
        if (right != 0) return left / right;
        else {
            cout << "Error: Divide by zero!\n";
            return 0;
        }
    default:
        cout << "Unknown operator!\n";
        return 0;
    }
}

void func(string str)
{
    stack<int> s;
    stringstream ss(str);
    string token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            int result = calc(left, token[0], right);
            s.push(result);
        }
        else
        {
            s.push(stoi(token));
        }
    }
    cout << s.top() << endl;
}

int main()
{
    string str = "15 7 + 2 *";
    func(str);
    return 0;
}
