/*
  Question :-
  You are given an array of strings strs[], consisting of lowercase letters. Your task is to find the longest common prefix shared among all the strings. 
  If there is no common prefix, return an empty string "".
  A common prefix is a substring that appears at the beginning of all the strings in the array. 
  The task is to identify the longest such prefix that all strings share.

*/

//Code :- 
#include<iostream>
#include<vector>
using namespace std;
void prefixStr(string arr[],int size)
{
  if(size == 0)
  {
      cout<<""<<endl;
  }
  else if(size == 1)
  {
    cout<<arr[0]<<endl;
  }
  else 
  {
    string str = arr[0];
    vector<char>list;
    for(int i = 1; i<size; i++)
      {
          int j  = 0;
          string curStr = arr[i];
          list.clear();
          while(j<str.size() && j<curStr.size() && str.at(j) == curStr.at(j))
            {
              list.push_back(str.at(j));
              j++;
            }
      }
    if(list.size()!=0)
    {

      for(int i=0; i<list.size() ; i++)
        {
          cout<<list[i];
        }
        cout<<"\n";
    }
    else
    {
      cout<<""<<endl;
    }
  }
}
int main()
{
  string arr[] = {"flower", "flow", "flight"};
  int size = sizeof(arr) / sizeof(arr[0]);
  prefixStr(arr,size);
  return 0;
}
