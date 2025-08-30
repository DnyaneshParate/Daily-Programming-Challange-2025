/*
  Question :- 
  You are given two integers, N and M. Your task is to find the Least Common Multiple (LCM) of these two numbers. 
  The LCM of two integers is the smallest positive integer that is divisible by both N and M.
*/

// Code :- 
#include<iostream>
using namespace std;
void leastLcm(int x , int y)
{
    int bigger = max(x,y);
    long long lcm = bigger;
    while(true)
    {
        if(lcm%x==0 && lcm%y==0)
        {
            cout<<lcm<<endl;
            break;
        }
        lcm+=bigger;
    }
}
int main()
{
    int x  = 123456, y = 789012;
    leastLcm(x,y);
    return 0;
}
