//Problem : Sort an Array of 0s, 1s, and 2s
//You are given an array arr consisting only of 0s, 1s, and 2s. The task is to sort the array in increasing order in linear time (i.e., O(n)) without using any extra space. 
//This means you need to rearrange the array in-place.

//Code :- 
#include<iostream>
using namespace std;
void sortArr(int arr[],int size)
{
    if(size>1)
    {
        for(int i = 0; i < size-1; i ++)
        {
            for(int j = i+1; j<size ; j++)
            {
                if(arr[i]>arr[j])
                {
                    swap(arr[i] , arr[j]);
                }
            }
        }
    }
}
int main()
{   
    int size;
    cin>>size;
    int arr[size];
    for(int i =0;i<size;i++)
    {
        cin>>arr[i];
    }
    sortArr(arr,size);
    cout<<"[";
    for(int i = 0 ; i<size ; i++)
    {
        cout<<arr[i];
        if(i<size-1)
        {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
    return 0;
}

