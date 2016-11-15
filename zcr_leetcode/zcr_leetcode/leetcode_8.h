//8. String to Integer (atoi) 
//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//  Notes : It is intended for this problem to be specified vaguely(ie, no given input specs).
//You are responsible to gather all the input requirements up front.

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int neg=1;
		while (str[i] == ' ')
		{
			i++;
		}
		if ('9' < str[i]  || str[i] <'0' )
		{
			if (str[i] == '-')
			{
				neg = -1;
			}
			else if (str[i] == '+')
			{
				neg = 1;
			}
			else {
				return 0;
			}
			++i;
		}
		
		long long result = 0;
		for (; i < str.length(); i++)
		{
			if ('9' < str[i] || str[i] <'0')
			{
				break;
			}
			result = result * 10 + (str[i]-'0');
			if (result*neg >= INT_MAX)
				return INT_MAX;
			if (result*neg <= INT_MIN)
				return INT_MIN;
		}
		return result*neg;
	}
	void test()
	{
		cout << this->myAtoi("1234") << endl;
		cout << this->myAtoi("   99") << endl;
		cout << this->myAtoi("   +-99") << endl;
		cout << this->myAtoi("   -99df4") << endl;
		cout << this->myAtoi("15342364691234") << endl;
		cout << this->myAtoi("-123") << endl;
		cout << this->myAtoi("9223372036854775809") << endl;

		system("pause");
	}
};