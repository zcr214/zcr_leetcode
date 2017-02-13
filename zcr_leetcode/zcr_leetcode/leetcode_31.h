//31. Next Permutation 
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 ¡ú 1, 3, 2
//3, 2, 1 ¡ú 1, 2, 3
//1, 1, 5 ¡ú 1, 5, 1
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		for (; i >0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				break;
			}
		}
		if (i > 0)
		{
			int num1=i-1;
			for (int x=nums.size()-1; x>num1; x--)
			{
				if (nums[x]>nums[num1])
				{
					swap(nums[x], nums[num1]);
					break;
				}
			}
			reverse(nums.begin()+num1+1,nums.end());
		}
		else{ 
			reverse(nums.begin(), nums.end());
		}

	}
	void test()
	{
		vector<int> sample = {1,2};
		this->nextPermutation(sample);


		system("pause");
	}
};