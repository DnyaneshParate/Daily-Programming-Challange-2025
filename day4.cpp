/*
Question :- 
You are given two sorted arrays arr1 of size m and arr2 of size n. Your task is to merge these two arrays into a single sorted array without using any extra space (i.e., in-place merging). 
The elements in arr1 should be merged first, followed by the elements of arr2, resulting in both arrays being sorted after the merge.
*/

//Code :- 
#include<iostream>
#include<algorithm>
using namespace std;
void swapArr(int arr1[],int m,int arr2[], int n)
{
    int i = 0 , j = 0,temp;
    while(i<m)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            temp = arr2[0];
            arr2[0] = arr1[i];
            arr1[i] = temp;
            sort(arr2 , arr2+n);
        }
    }
}
int main()
{
    int arr1[] = {1, 3, 5, 7}, arr2[] = {2, 4, 6, 8};
    int m = sizeof(arr1) / sizeof(arr1[0]), n = sizeof(arr2) / sizeof(arr2[0]);
    swapArr(arr1,m,arr2,n);
    for(int i =0; i < m ; i++)
    {
        cout<<arr1[i];
    }
    cout<<endl;
    for(int i =0; i < n ; i++)
    {
        cout<<arr2[i];
    }
    cout<<endl;
    return 0;
}
