//15. 3Sum
//Given an array S of n integers, 
//are there elements a, b, c in S such that a + b + c = 0 ?
//Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//	   For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	   A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		//结果正确但是超时
		vector<vector<int>> result = {};
		unordered_map<int, int> resultmap;
     	if (nums.size()<3)
		{
			return result;
		}
		sort(nums.begin(), nums.end());
			
		
		for (int first = 0; first < nums.size()-2; first++)
		{
			if (first>0&&nums[first]==nums[first-1])
			{
				continue;
			}
			unordered_map<int, int> umap;
			unordered_map<int, int> secondmap;
			for (int i = first+1; i < nums.size(); i++)
			{
				int NumtoFind = 0 - nums[first] - nums[i];
				
				if (secondmap.find(NumtoFind)!=secondmap.end())
				{
					continue;
				}
				if (umap.find(NumtoFind) != umap.end())
				{						
				    secondmap[NumtoFind] = i;
					result.push_back({nums[first],nums[i],NumtoFind});		
					
				}
				umap[nums[i]]= i;
			}
		}

		return result;
	}
	vector<vector<int>> threeSum2(vector<int>& nums)
		
	{//别人的算法，O(n^2),从两头往中间靠
		int len = nums.size();
		vector<vector<int>> output;

		sort(begin(nums), end(nums));

		for (int p1 = 0; p1 < len - 2; ++p1) {
			if (p1 != 0 && (nums[p1 - 1] == nums[p1])) continue;
			if (nums[p1] + nums[p1 + 1] + nums[p1 + 2] > 0) break;
			for (int p2 = p1 + 1, p3 = len - 1; p2 < p3;) {
				if (p2 != p1 + 1 && nums[p2 - 1] == nums[p2]) {
					++p2;
					continue;
				}
				if (p3 != len - 1 && nums[p3] == nums[p3 + 1]) {
					--p3;
					continue;
				}

				int sum = nums[p1] + nums[p2] + nums[p3];
				if (sum == 0) {
					output.push_back({ nums[p1], nums[p2], nums[p3] });
					++p2, --p3;
				}
				else if (sum < 0) ++p2;
				else --p3;
			}
		}
		return output;
	}
	void test()
	{

	//	vector <int> strs = { -1, 0, 1, 2, -1, -4 };
		//vector <int> strs = { 0, 0, 0, 0 };
		//vector<int>strs = { -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 };
		vector<int>strs={7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6
	};
		vector<vector<int>> solv = this->threeSum(strs);
		for (int i = 0; i < solv.size(); i++)
		{
			for (int j = 0; j < solv[i].size(); j++)
			{
				cout << solv[i][j]<<" ";
			}
			cout << endl;
		}

		system("pause");
	}
};