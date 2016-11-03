//5. Longest Palindromic Substring
//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, 
//and there exists one unique longest palindromic substring.


#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() <= 1)
		{
			return s;
		}
		string result;
		int ptr = 0;
		int start = ptr, end = ptr;
		int maxlen = 0;
		for (; ptr < s.length(); ++ptr)
		{
			if (maxlen>2 * (s.length() - ptr)+1)
			{
				break;
			}
			start = ptr;
			while (s[ptr] == s[ptr + 1])
			{
				ptr = ptr + 1;
			}
			end = ptr;
			while (start >= 0 && end < s.length() && s[start] == s[end])
			{
				--start;
				++end;
			}
			if (end - start -1 >= maxlen)
			{
				maxlen = end - start -1;
				result = s.substr(start+1, maxlen);
			}

		}
		return result;
	}



	void test()
	{
		
		cout<< this->longestPalindrome("abcdefggfedcccc")<<endl;
		cout << this->longestPalindrome("aaa") << endl;
		cout << this->longestPalindrome("aa") << endl;
		cout << this->longestPalindrome("a") << endl;
		cout << this->longestPalindrome("") << endl;
		system("pause");
	}
};