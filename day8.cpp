/*
  Question :- 
  You are given a string s that consists of multiple words separated by spaces. 
  Your task is to reverse the order of the words in the string. Words are defined as sequences of non-space characters. 
  The output string should not contain leading or trailing spaces, and multiple spaces between words should be reduced to a single space.
*/

// Code :- 

#include<iostream>
using namespace std;
void reverseStr(string str)
{
    int len = str.length(),j;
    bool condn = false;
    for(int i=len-1;i>=0;i--)
    {
        if(str.at(i) == ' ' && condn == false)
        {
            continue;
        }
        else
        {
            if(str.at(i)==' ' && condn == true)
            {
                j = i+1;
                while( j<len && str.at(j) !=' ' )
                {
                    cout<<str.at(j);
                    j++;
                }
                cout<<" ";
                condn  = false;
            }
            else
            {
                condn = true;
                if(i == 0 && str.at(i)!=' ')
                {
                    j = i;
                    while( j<len && str.at(j) !=' ' )
                    {
                        cout<<str.at(j);
                        j++;
                    }
                }
            }
        }
    }
    cout<<endl;
}
int main()
{
    string str = "    ";
    reverseStr(str);
    return 0;
}
