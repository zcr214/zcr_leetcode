//20. Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//
//The brackets must close in the correct order, 
//"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

	bool isValid(string s) {
		vector<char> expectChar = {};

		for (int i = 0; i<s.length(); i++)
		{
			if (s[i] == '(')
			{
				expectChar.push_back(')');
				continue;
			}

			if (s[i] == '[')
			{
				expectChar.push_back(']');
				continue;
			}

			if (s[i] == '{')
			{
				expectChar.push_back('}');
				continue;
			}
			if (expectChar.size()>0)
			{
				char x = expectChar[expectChar.size() - 1];
				expectChar.pop_back();
				if (x == s[i])
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else{
				return false;
			}


		}
		if (expectChar.size() == 0)
		{
			return true;
		}
		return false;

	}
	void test()
	{
		bool ok = this->isValid("(()[]{[()]}");
		cout << ok << endl;

		system("pause");
	}
};