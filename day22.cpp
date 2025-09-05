/*
  First Element to Repeat k Times
  You are given an array of integers and an integer k. Your task is to find the first element in the array that appears exactly k times.
  If no such element exists, return -1.
*/


// Code :- 
#include<iostream>
using namespace std;
void firstElement(int arr[],int size,int k)
{
    for(int i = 0;i<size;i++)
    {
        int currNum = arr[i];
        int count = 1;
        bool alreadyChecked = false;
        for (int j = 0; j < i; j++) {
        if (arr[i] == arr[j]) {
            alreadyChecked = true;
            break;
            }
        }
if (alreadyChecked) continue;

        for(int j = i+1;j<size;j++)
        {
            if(currNum == arr[j])
            {
                count++;
            }
        }
        if(count == k)
        {
            cout<<currNum<<endl;
            return;  
        }
    }
    cout<<"-1\n";
}
int main()
{
    int arr []= {6, 6, 6, 6, 7, 7, 8, 8, 8}, k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    firstElement(arr,size,k);
    return 0;
}
