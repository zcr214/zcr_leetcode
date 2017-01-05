//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//Input:Digit string "23"
//Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//	 Note :
//		  Although the above answer is in lexicographical order, 
//        your answer could be in any order you want
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	
	vector<string> letterCombinations(string digits) {
		if (digits.length()<1)
		{
			vector<string> no = {};
			return no;
		}
		vector<string> result= {""};
		vector<string> letters = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i < digits.length(); i++)
		{
			vector<string> store;
			for (int i_store = 0; i_store < letters[digits[i]-'2'].length(); i_store++)
			{
				vector<string> result_temp(result);
				for (int i_result_temp = 0; i_result_temp < result_temp.size(); i_result_temp++)
				{
					store.push_back(result_temp[i_result_temp]+letters[digits[i] - '2'][i_store]);
				}				
			}
			
			result = store;

		}
		return result;
	}
	void test()
	{

		string digits = "23";
		vector<string> result = this->letterCombinations(digits);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
		system("pause");
	}
};