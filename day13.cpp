/*
  Question :- 
  You are given a string s. Your task is to find and return the longest palindromic substring within the given string. 
  A palindrome is a string that reads the same forwards and backwards.

*/

// Code :- 
#include<iostream>
#include<vector>
using namespace std;
void checkPalindrome(string str)
{
    int len = str.length();
    if(len<=1)
    {
        cout<<str<<endl;
    }
    else
    {
        string best = "";
        for(int start = 0;start<len;start++)
        {
        int i = start, j = len-1;
        vector<char> vec1, vec2;
        while(i<j)
        {
            
            if(str.at(i)==str.at(j))
            {
                vec1.push_back(str.at(i));
                vec2.push_back(str.at(j));
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        if(i==j)
        {
            vec1.push_back(str.at(i));
        }
        for(int i=vec2.size()-1;i>=0;i--)
        {
            vec1.push_back(vec2[i]);
        }
        string cand = "";
        for(char c : vec1){ cand.push_back(c);
        }
        if(cand.size() > best.size()) {
            best = cand;
        }
    }
    cout<<best<<endl;
    }
}
int main()
{
    string str = "cbbd";
    checkPalindrome(str);
    return 0;
}
