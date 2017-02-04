//28. Implement strStr()
//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack,
//or - 1 if needle is not part of haystack.

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

	int strStr(string haystack, string needle) {
		if (needle.length() == 0) return 0;
		int index = 0;
		
		while(index<haystack.length())
		{
			if (haystack.length() - index < needle.length())
			{
				return -1;
			}
			int i = 0, nextindex = 0;
			for (; i < needle.length(); i++)
			{
  				if (haystack[index+i]==needle[i])
				{
					if (i != 0 && haystack[index + i] == needle[0] && nextindex ==0)
					{
						nextindex = i + index;
					}
					continue;
				}
				else
				{
					if (nextindex != 0)
					{
						index = nextindex;
					}
					else if (i != 0)
					{
						index+=i;
					}
					else
					{
						index++;
					}
 					break;
				}
			
			}
			if (i==needle.length())
			{
				return index;
			}

		}
		return -1;

	}
	void test()
	{
		int ok = this->strStr("mississippi","issip");
		cout << ok << endl;

		system("pause");
	}
};