#include <vector>
#include <hash_map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		hash_map<char,int> sub;
		int max = 0;

		for (int i = 0; i<s.length; i++)
		{

		}

	}

	
	
	void test()
	{
		string s = "abcdefa";
		
		int result = this->lengthOfLongestSubstring(s);
		printf("%d", result);
		system("pause");
	}
};