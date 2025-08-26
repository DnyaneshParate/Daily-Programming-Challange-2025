/*
  Question :- 
  You are given a string s consisting of different types of parentheses: (), {}, and []. Your task is to determine whether the given string is valid.
  A string is considered valid if:
  1. Every opening bracket has a corresponding closing bracket of the same type.
  2. The brackets are closed in the correct order. This means that a closing bracket must close the most recent unmatched opening bracket.

*/

// Code :- 
#include<iostream>
#include<stack>
using namespace std;
bool checkParen(string str)
{
    stack<char> s;
    int len = str.length(),i = 0;
    while(i<len)
      {
          if(str.at(i) =='[' || str.at(i) == '{' || str.at(i) == '(')
          {
              s.push(str.at(i));
          }
          else
          {
              if(s.empty())
              {
                return false;
              }
              else if(s.top() == '[' && str.at(i) == ']')
              {
                  s.pop();
              }
              else if(s.top() == '{' && str.at(i) == '}')
              {
                  s.pop();
              }
            else if(s.top() == '(' && str.at(i) == ')')
              {
                  s.pop();
              }
              else
            {
                return false;
            }
          }
            i++;
      }
    if(s.empty())
    {
      return true;
    }
    else
    {
      return false;
    }
}
int main()
{
  string str = "({[]})";
  if(checkParen(str))
  {
    cout<<"True\n";
  }
  else
  {
    cout<<"False\n";
  }
  return 0;
}
