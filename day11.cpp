
/*
  Question :-
   Permutations of a String
You are given a string s. Your task is to generate and return all possible permutations of the characters in the string. 
A permutation is a rearrangement of the characters in the string, and each character must appear exactly once in every permutation. 
If there are duplicate characters in the string, the resulting permutations should also be unique (i.e., no repeated permutations).

*/

// Code :- 
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void generatePermutations(const string &inputString, set<string> &permutationsSet, string &currentPermutation, vector<bool> &isVisited)
{
    if (currentPermutation.length() == inputString.length())
    {
        permutationsSet.insert(currentPermutation);
        return;
    }

    for (int i = 0; i < inputString.length(); i++)
    {
        if (!isVisited[i])
        {
            currentPermutation += inputString[i];
            isVisited[i] = true;

            generatePermutations(inputString, permutationsSet, currentPermutation, isVisited);

            isVisited[i] = false;
            currentPermutation.pop_back();
        }
    }
}

int main()
{
    string inputString = "aacb";
    set<string> allPermutations;
    string currentPermutation = "";
    vector<bool> isVisited(inputString.length(), false);

    generatePermutations(inputString, allPermutations, currentPermutation, isVisited);

    cout << "Permutations of \"" << inputString << "\":" << endl;
    for (const string &permutation : allPermutations)
    {
        cout << permutation << endl;
    }

    return 0;
}
