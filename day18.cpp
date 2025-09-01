
/*
  Question :-
  Count the Number of Divisors of a Number
Given a positive integer N, your task is to find the total number of divisors (factors) of N. 
A divisor of N is any integer that divides N without leaving a remainder.
A divisor of a number is any integer that divides the number evenly (i.e., without a remainder). 
For example, for N = 12, its divisors are 1, 2, 3, 4, 6, 12, so the total number of divisors is 6.

*/


// Code :- 
#include<iostream>
using namespace std;
void divisors(long long num)
{
    int count = 0;
    for(long long i =1;i*i<=num;i++)
    {
        if(num%i == 0)
        {
            if(i*i==num)
            {
                count++;
            }
            else
            {
                count+=2;
            }
        }
    }
    cout<<count<<endl;
}
int main()
{
    long long num = 997;
    divisors(num);
    return 0;
}
