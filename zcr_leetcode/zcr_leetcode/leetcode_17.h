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
		vector<string> result = {"nihao"};
		for (int i = 0; i < digits.length(); i++)
		{
			printf("%d",i);
		}
		return result;
	}
	void test()
	{

		string digits = "234";
		vector<string> result = this->letterCombinations(digits);

		system("pause");
	}
};