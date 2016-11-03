//7. Reverse Integer
//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//	  Example2 : x = -123, return -321
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		if (x<INT_MIN || x>INT_MAX)
		{
			return 0;
		}
		
		while (x)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
		return (result<INT_MIN || result>INT_MAX) ? 0: result;
		

	}
	void test()
	{
		cout << this->reverse(1234) << endl;
		cout << this->reverse(-1234) << endl;
		cout << this->reverse(1534236469) << endl;
		
		system("pause");
	}
};