//9. Palindrome Number
//Some hints :
//
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, 
//note the restriction of using extra space.
//
//You could also try reversing an integer.
//However, if you have solved the problem "Reverse Integer", 
//you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		int array[1024] = { 0 };
		int i = 0;
		if (x < 0)
		{
			return false;
		}
		while (x)
		{
			array[i] = x % 10;
			x /= 10;
			++i;
		}
		--i;
		int i2 = 0;
		while (array[i]==array[i2])
		{
			
			if (i2 >= i)
				return true;
			--i;
			++i2;	
		}
		return false;

	}
	void test()
	{
		cout << this->isPalindrome(1234321) << endl;
		cout << this->isPalindrome(1) << endl;
		cout << this->isPalindrome(1534236469) << endl;

		system("pause");
	}
};