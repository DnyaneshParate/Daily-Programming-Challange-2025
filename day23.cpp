/*
  Question :-
  You are given an array of integers arr and a positive integer k. Your task is to find the maximum element in each sliding window of size k. 
  The window slides from left to right, one element at a time, and you need to return the maximum element for each of these windows.

*/

// Code :- 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> subArr(int arr[],int size,int k)
{
    vector<int> newArr;
    int holdArr[k];
    for(int i= 0;i<=size-k;i++)
    {
        for(int j = 0 ; j<k;j++)
        {
            holdArr[j] = arr[i+j];
        }
        sort(holdArr,holdArr+k);
        newArr.push_back(holdArr[k-1]);
    }   
    return newArr;
}
int main()
{
    int arr[] = {7, 7, 7, 7},k = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> final;
    final = subArr(arr,size,k);
    for(int i=0;i<final.size();i++)
    {
        cout<<final[i]<<" ";
    }
    cout<<endl;
    return 0;
}
