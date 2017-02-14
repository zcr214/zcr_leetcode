//38 .Count and Say 
//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

	string countAndSay(int n) {
		string x = "1";
		for (int i = 0; i<n - 1; i++)
		{
			x = generate(x);
		}
		return x;
	}
	string generate(string x)
	{
		char can = x[0];
		int count = 0;
		string result = "";
		for (int i = 0; i<x.length(); i++)
		{
			if (can == x[i])
			{
				count++;
			}
			else
			{
				result = result + to_string(count) + can;
				can = x[i];
				count = 1;
			}
			if (i == x.length() - 1)
			{
				result = result + to_string(count) + can;
			}
		}
		return result;

	}
	void test()
	{

		//long long dvd = -2147483648;
		cout << this->countAndSay(12) << endl;

		system("pause");
	}
};