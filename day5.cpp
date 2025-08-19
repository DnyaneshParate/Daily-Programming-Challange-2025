/*
  Question :- 
  You are given an integer array arr of size n. An element is considered a leader if it is greater than all the elements to its right. 
  Your task is to find all such leader elements in the array.
*/

// Code :- 

#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> vec , int num)
{
    for(int i = 0; i < vec.size();i++)
    {
        if(vec[i] == num)
        {
            return false;
        }
    }
    return true;
}
vector<int> leaderArr(int arr[] , int size)
{
  vector<int> newArr;
  for(int i = 0; i < size-1;i++)
  {
      bool condn = true;
    //   int ind = i+1;
      for(int j = i+1; j<size; j++)
      {
            if(arr[i]>arr[j])
            {
                continue;
            }
            else
            {
                condn = false;
                break;
            }
      }
      if(condn && check(newArr,arr[i]))
      {
          newArr.push_back(arr[i]);
      }
  }
  if(check(newArr , arr[size-1]))
  {
    newArr.push_back(arr[size-1]);
  }
  return newArr;
}
int main()
{
  int arr[] = {16, 17, 4, 3, 5, 4, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  vector<int> newArr;
  newArr = leaderArr(arr,size);
  for(int i = 0 ;i<newArr.size();i++)
    {
      cout<<newArr[i]<<" ";
    }
  cout<<"\n";
  return 0;
}
