/*
  Question :- 
  You are given a string S, and your task is to find the length of the longest substring that contains no repeating characters. 
  A substring is a contiguous block of characters in the string.
  In this problem, you need to find the length of the longest substring where all the characters are unique. 
  The substring can be formed by starting at any position in the string, but it must not contain any repeated characters.
*/

// Code :-
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void longSubStr(string str)
{
    vector<char> final;
    int len = 0;
    for(int i = 0;i<str.length();i++)
    {
        auto it = find(final.begin(), final.end(), str[i]);
        if(it == final.end())
        {
            final.push_back(str[i]);
        }
        else
        {
            final.erase(final.begin(),it+1);
            final.push_back(str.at(i));
        }
        len = max(len, (int)final.size());
    }
    cout<<len<<endl;
}
int main()
{
    string str = "dvdf";
    longSubStr(str);
    return 0;
}
