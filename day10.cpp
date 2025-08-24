/*
  Question :- 
  You are given an array of strings strs[]. Your task is to group all the strings that are anagrams of each other. 
  An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
  The goal is to return the grouped anagrams as a list of lists, where each sublist contains words that are anagrams of each other.
*/

// Code :- 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isAnagram(string a, string b) {    
    if (a.length() != b.length()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
vector<string> grpAnagram(vector<string> arr)
{
    vector <string>final;
    if(arr.size()<2)
    {
        if(arr.size() == 1)
        {
            final.push_back("[" + arr[0] + "]");
        }
    }
    else
    {
        while(arr.size()>0)
        {
            string str = arr[0];
            string temp = "[" +str;
            final.push_back(temp);
            for(int i=1;i<arr.size() ;i++)
            {
                string curStr = arr[i];
                if(str.length() == curStr.length())
                {
                    if(isAnagram(str, curStr))
                    {
                        final.push_back(arr[i]);
                        arr.erase(arr.begin() + i);
                        i--; 
                    }
                }
            }
            string last = final.back();
            last+= "]";
            final[final.size()-1] = last;
            arr.erase(arr.begin()+0);
        }
        
    }
    return final;
}
int main()
{
    vector<string>arr = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<string> final = grpAnagram(arr);
    cout<<"[ ";
    for(int i = 0;i<final.size();i++)
    {
        cout<<final[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}
