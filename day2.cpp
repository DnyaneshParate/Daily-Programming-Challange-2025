/*
  Question :- 
    You are given an array arr containing n-1 distinct integers.
    The array consists of integers taken from the range 1 to n, meaning one integer is missing from this sequence.
    Your task is to find the missing integer.
*/

// Code :- 
#include<iostream>
#include<algorithm>
using namespace std;
void missNum(int arr[] , int size)
{
    int miss = 0,currNum = 1;
    for(int i = 0 ; i < size ; i ++)
    {
        if(arr[i]!=currNum)
        {
            miss = currNum;
            break;
        }
        else if(i==size-1 && miss == 0)
        {
            miss = currNum+1;
        }
        else
        {
            currNum++;
        }
    }
    cout<<miss<<endl;
}
int main()
{
  int arr[] = {1,2,4,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  sort(arr, arr+size);
  missNum(arr,size);
  return 0;
}
