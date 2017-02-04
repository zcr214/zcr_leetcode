//29. Divide Two Integers
//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

	int divide(int dividend, int divisor) {
		int result = 0;
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
		int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);

		while (dvd >= dvs)
		{
			long divisor_temp = dvs;
			long result_temp = 1;
			while (dvd >= (divisor_temp << 1))
			{
				divisor_temp <<= 1;
				result_temp <<= 1;
			}

			result += result_temp;
			dvd -= divisor_temp;
		}
		return result = sign == 1 ? result : -result;
	}
	void test()
	{

		//long long dvd = -2147483648;
		cout << this->divide(123, 11) << endl;

		system("pause");
	}
};