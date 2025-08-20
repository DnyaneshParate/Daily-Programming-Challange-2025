/*
  Question :- 
  You are given an integer array arr of size n. Your task is to find all the subarrays whose elements sum up to zero. 
  A subarray is defined as a contiguous part of the array, and you must return the starting and ending indices of each subarray.

*/

// Code :- 

#include<iostream>
#include<vector>
using namespace std;
void formSubArr(int arr[],int size, vector<int> &begin , vector<int> &end)
{
    for(int i = 0; i<size;i++)
    {
        int sum = 0;
        for(int j = i; j<size; j++)
          {
              sum += arr[j];
              if(sum == 0 && i!=j)
              {
                  begin.push_back(i);
                  end.push_back(j);
              }
          }
    }
}
int main()
{
  int arr[] = {0,0,0};
  int size = sizeof(arr) / sizeof(arr[0]);
  vector<int> begin , end;
  formSubArr(arr,size,begin,end);
  cout<<"[";
  for(int i = 0; i<begin.size();i++)
  {
      cout<<"("<<begin[i]<<","<<end[i]<<")";
      if(i<begin.size()-1)
      {
          cout<<",";
      }
  }
  cout<<"]\n";
  return 0;
}
