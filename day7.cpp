/*
  Question :- 
  You are given an array height[] of non-negative integers where each element represents the height of a bar in a histogram-like structure.
  These bars are placed next to each other, and the width of each bar is 1 unit. 
  When it rains, water gets trapped between the bars if there are taller bars on both the left and right of the shorter bars. 
  The task is to calculate how much water can be trapped between these bars after the rain.

The amount of water trapped above any bar is determined by the difference between the height of the bar and the minimum height of the tallest bars on its left and right. 
For example, if a bar is surrounded by taller bars, the water will be trapped above it, filling the space up to the height of the shorter of the two taller bars.

*/

// Code :- 
#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int> &height)
{
  int n = height.size();
  if(n==0)
  {
    return 0;
  }
  vector<int> left(n) , right(n);
  int maxLeftBar = 0, maxRightBar = 0;

  for(int i =0;i<n;++i)
    {
      maxLeftBar = max(maxLeftBar , height[i]);
      left[i] = maxLeftBar;
    }
  for(int i =n-1;i>=0 ; --i)
    {
      maxRightBar = max(maxRightBar , height[i]);
      right[i] = maxRightBar;
     }
  int trapWater = 0;
  for(int i=0;i<n;++i)
    {
      trapWater += min(left[i],right[i]) - height[i];
    }
  return trapWater;
}
int main()
{
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout<<trap(height)<<endl;
  return 0;
}
