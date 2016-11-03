//3. Longest Substring Without Repeating Characters
//Given a string, find the length of the longest substring without repeating characters.
//Examples:
//Given "abcabcbb", the answer is "abc", which the length is 3.
//Given "bbbbb", the answer is "b", with the length of 1.
//Given "pwwkew", the answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		unordered_map<char,int> sub;
		int max = 0;
		int left=0,i= 0;
		for (; i<s.length(); i++)
		{
			if (sub.find(s[i]) != sub.end()&&sub[s[i]] >= left)
			{
				max = max>i - left ? max : i - left;
				left = sub[s[i]]+1;
			}
			sub[s[i]] = i;
		}
		return max = max>i - left ? max : i - left;
	}

	
	
	void test()
	{
	 
		cout << this->lengthOfLongestSubstring("abcabcd")<< endl;
		system("pause");
	}
};