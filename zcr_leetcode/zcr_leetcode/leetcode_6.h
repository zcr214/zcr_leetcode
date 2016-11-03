//6. ZigZag Conversion 
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line : "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> zig(numRows);
		int groupsize = numRows == 1 ? 1 : numRows * 2 - 2;
		for (int i = 0; i<s.length(); i++)
		{
			int res = i%groupsize;
			zig[res >= numRows ? groupsize - res : res] += s[i];
		}
		string result = "";
		for (int j = 0; j<numRows; j++)
		{
			result += zig[j];
		}
		return result;
	}
	string convert2(string s, int numRows) {
		//别人的算法
		if (numRows == 1) return s;
		vector<string> bucket(numRows);
		for (int i = 0; i < s.size(); ++i) {
			int j = numRows - 1 - abs(i % (numRows * 2 - 2) - numRows + 1);
			bucket[j] += s[i];
		}
		string ans;
		for (string b : bucket) {
			ans += b;
		}
		return ans;
	}
	void test()
	{
		cout << this->convert("a", 1) << endl;
		cout << this->convert("PAYPALISHIRING", 3) << endl;
		cout << this->convert2("a", 1) << endl;
		cout << this->convert2("PAYPALISHIRING", 3) << endl;
		//printf("%s\n",this->convert(xx,5));
		system("pause");
	}
};