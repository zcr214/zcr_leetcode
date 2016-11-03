
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum1(vector<int>& nums, int target) {
		//测试结果为336ms
		vector<int> result;
		int len = nums.size();
		int i, j;
		for (i = 0; i < len-1; i++)
		{
			int rest = target - nums[i];
			for (j = i + 1; j < len; j++)
			{
				if (rest == nums[j])
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		
	}
	vector<int> twoSum2(vector<int>& nums, int target) {
		//别人的答案,13ms
		vector<int> result;
		unordered_map<int, int> hash;
		for (int i = 0; i<nums.size(); i++)
		{
			int numToFind = target - nums[i];
			if (hash.find(numToFind) != hash.end())
			{
				result.push_back(i);
				result.push_back(hash[numToFind]);
				return result;
			}
			hash[nums[i]] = i;
		}
		return result;
	}
	void test()
	{
		vector<int> arr= { 3, 2, 4 ,-5,-2};
		int target = 6;
		vector<int> result=this->twoSum1(arr,target);
		printf("%d,%d",result[0],result[1]);
		system("pause");
	}
};