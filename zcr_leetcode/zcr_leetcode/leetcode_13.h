//13. Roman to Integer 
//Given a roman numeral, convert it to an integer.

//Input is guaranteed to be within the range from 1 to 3999.
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	
	int romanToInt(string s) {
		string str[4][9] = {
			{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "M", "MM", "MMM" }
		};
		int x[4] = { 1, 10, 100, 1000 };
		int result = 0;
		int ptr = 0;
		for (int i = 3; i >= 0; i--)
		{
			int j = i==3?2:8;
			while (str[i][j]!=""&&j>=0)
			{
				if (s.find(str[i][j])==ptr)
				{
					result  += x[i]*(j+1);
					ptr += str[i][j].length();
					break;
				}
				j--;
			}
			
		}
		return result;
	}

	void test()
	{

		//cout << this->romanToInt("CXXIII") << endl;
		cout << this->romanToInt("MDCCCLXXXIV") << endl;
		system("pause");
	}
};