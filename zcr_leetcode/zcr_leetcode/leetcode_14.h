//14. Longest Common Prefix 
//Write a function to find the longest common prefix string amongst an array of strings. 
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:

	string longestCommonPrefix(vector<string>& strs) {
		int num = 0;
		bool finish = false;
		string result = "";
		if (strs.empty())
		{
			return result;
		}
		while (!finish)
		{
			for (int i = 0; i < strs.size(); i++)
			{
				if (strs[i][num] != strs[0][num]||strs[0][num]==NULL)
				{
					finish = true;
					break;
				}
			}
			if (!finish)
			{
				result += strs[0][num];
				num++;
			}

		}
		return result;
	}
	void test()
	{

		vector <string> strs = { "abc", "abcdf", "abctg" };
		cout << this->longestCommonPrefix(strs) << endl;
		system("pause");
	}
};