/*
  Question :- 
  You are given an array arr containing n+1 integers, where each integer is in the range [1, n] inclusive.
  There is exactly one duplicate number in the array, but it may appear more than once. 
  Your task is to find the duplicate number without modifying the array and using constant extra space.
*/

// Code :- 
#include<iostream>
using namespace std;
void duplicateElement(int arr[] , int size)
{
    bool condn = false;
    for(int i = 0 ; i < size; i++)
      {
          for(int j = i+1; j<size ; j++)
            {
                if(arr[i] ==  arr[j])
                {  
                  cout<<arr[i]<<endl;
                  condn = true;
                  break;
                }
            }
        if(condn)
        {
            break;
        }
      }
  if(!condn)
  {
      cout<<"No Duplicate Element Present\n";
  }
}
int main()
{
  int arr[] = {3, 1, 3, 4, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  duplicateElement(arr , size);
  return 0;
}
