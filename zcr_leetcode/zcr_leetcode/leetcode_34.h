//34. Search for a Range
//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:

	vector<int> searchRange(vector<int>& nums, int target) {
		
		vector<int> result = {};
		if (nums.size() == 0)
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		else if (nums.size() == 1)
		{
			if (nums[0] == target)
			{
				result.push_back(0);
				result.push_back(0);
			}
			else
			{
				result.push_back(-1);
				result.push_back(-1);
			}
		}
		else
		{
			result.push_back(findleft(nums, target, 0, nums.size() - 1));
			result.push_back(findright(nums, target, 0, nums.size() - 1));
		}

		return result;
	}
	int findleft(vector<int>& nums,int target,int left,int right)
	{
		if (nums[left] == target)
		{
			return left;
		}
		if (nums[left] < target)
		{
			if (right-left==1)
			{
				if (nums[right] == target) return right;
				if (nums[right] != target) return -1;
			}
			else if ( nums[(right + left) / 2] >= target)
			{
				return findleft(nums, target, left, (right + left) / 2);
			}
			else if (nums[(right + left) / 2] < target)
			{
				return findleft(nums, target, (right + left) / 2,right);
			}
		}
		else
		{
			return -1;
		}
		
		
	}
	int findright(vector<int>& nums, int target, int left, int right)
	{
		if (nums[right] == target)
		{
			return right;
		}
		if (nums[right] > target)
		{
			if (right - left == 1)
			{
				if (nums[left] == target) return left;
				if (nums[left] !=target) return -1;
			}
			else if (nums[(right + left) / 2] <= target)
			{
				return findright(nums, target, (right + left) / 2,right);
			}
			else if ( nums[(right + left) / 2] > target)
			{
				return findright(nums, target,left, (right + left) / 2);
			}
		
		}
		else
		{
			return -1;
		}
	
	}
	void test()
	{

		//vector<int> sample = { 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 9, 9 };
		//vector<int> result=this->searchRange(sample, 6);
		vector<int> sample = { 2, 2 };
		vector<int> result = this->searchRange(sample, 1);
		cout << result[0]<< endl;
		cout << result[1] << endl;
		system("pause");
	}
};