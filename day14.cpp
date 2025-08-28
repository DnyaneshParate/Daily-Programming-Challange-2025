
/*
  Question :- 
  Count Substrings with Exactly K Distinct Characters
You are given a string s of lowercase English alphabets and an integer k. Your task is to count all possible substrings of s that contain exactly k distinct characters.


*/


// Code :- 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostK(string &s, int k) {
        int n = s.size();
        int left = 0, count = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;
            while ((int)freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int substrCountExactlyK(string s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s = "pqpqs";
    int k = 2;
    cout << sol.substrCountExactlyK(s, k) << endl;
    return 0;
}
