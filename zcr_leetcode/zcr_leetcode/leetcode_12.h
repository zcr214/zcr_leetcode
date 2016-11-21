//12. Integer to Roman
//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string result = "";
		string roman[4] = { "" };
		string one[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		string ten[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		string hundred[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		string thousand[4] = { "", "M", "MM", "MMM" };
		int i = 0;
		if (num > 3999 || num < 1)
		{
			return result;
		}

		roman[0] = one[num % 10 ];
		num /= 10;
		if (num)
		{
			roman[1] = ten[num % 10 ];
		}
		num /= 10;
		if (num)
		{
			roman[2] = hundred[num % 10 ];
		}
		num /= 10;
		if (num)
		{
			roman[3] = thousand[num % 10 ];
		}
		result = roman[3] + roman[2] + roman[1] + roman[0];
		return result;
	}
	string intToRoman2(int num) {
		char* str[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }
		};

		string val = "";
		val += str[3][num / 1000 % 10];
		val += str[2][num / 100 % 10];
		val += str[1][num / 10 % 10];
		val += str[0][num % 10];

		return val;
	}



	void test()
	{
		
		cout << this->intToRoman(3999) << endl;

		system("pause");
	}
};