//22. Generate Parentheses 
//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<string> generateParenthesis(int n) {
		vector<string> result = {};
		if (n == 0)
		{
			return result;
		}
		this->getAString(result,"", n, n);
		return result;
	}
	void getAString(vector<string> &result, string temp, int left_remain, int right_remain)
	{
		if (left_remain == 0 )
		{
			if (right_remain == 0)
			{
				result.push_back(temp);
				return;
			}
			else
			{
				
				getAString(result, temp + ")", left_remain, right_remain-1);
			}

		}

		else if (left_remain > 0)
		{
			if (left_remain < right_remain)
			{
			
				getAString(result, temp + "(", left_remain-1, right_remain);
			
				getAString(result, temp + ")", left_remain, right_remain-1);
			}
			else if (left_remain==right_remain)
			{
				
				getAString(result, temp + "(", left_remain-1, right_remain);
			}
			else
			{
				return;
			}
		}
	}
	void test()
	{

		vector<string> result = this->generateParenthesis(4);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
		system("pause");
	}
};

