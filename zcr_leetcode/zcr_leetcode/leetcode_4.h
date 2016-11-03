//4. Median of Two Sorted Arrays
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//
//Example 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is(2 + 3) / 2 = 2.5

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		for (int i = 0; i < nums2.size(); i++)
		{
			nums1.push_back(nums2[i]);
		}
		sort(nums1.begin(),nums1.end());
		double result = 0.0;
		int len = nums1.size();
		if (len % 2 == 0)
		{
			result = (nums1[len / 2] + nums1[len / 2 - 1]) / 2.0;
		}
		else
		{
			result = nums1[len / 2];
		}
		return result;
	}



	void test()
	{
		vector<int> nums1 = { 2, 3, 4, 5 };
		vector<int> nums2 = { 1, 2, 4 };
		cout << this->findMedianSortedArrays(nums1, nums2) << endl;
		system("pause");
	}
};