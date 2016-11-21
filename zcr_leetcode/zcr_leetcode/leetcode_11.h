//Container With Most Water
//Given n non - negative integers a1, a2, ..., an, 
//where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).
//Find two lines, which together with x - axis forms a container,
//such that the container contains the most water.
//
//Note: You may not slant the container.
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		//O(n^2)
		int result = 0;
		for (int pre = 0; pre < height.size()-1; pre++)
		{
			for (int post = pre + 1; post < height.size(); post++)
			{
				int area = height[post]>height[pre] ? height[pre] * (post - pre) : height[post] * (post - pre);
				if (area > result)
				{
					result = area;
				}
			}
		}
		return result;
	}
	int maxArea2(vector<int>& height) {
		//O(n)
		int result = 0;
		int pre = 0, post = height.size() - 1;
		while ( pre < post)
		{
			
				int h = height[post]>height[pre] ? height[pre] : height[post];
				int area = h*(post - pre);
				
				result = area > result ? area : result;
				 
				while (  height[pre] <= h&&pre < post) ++pre;
				while (height[post] <= h&&pre < post) --post;
		}
		return result;
	}
	void test()
	{
		vector<int> t = { 1, 2, 3, 4, 3, 5, 6 };
		vector<int> t2 = { 2, 1 };
		cout << this->maxArea2(t2) << endl;

		system("pause");
	}
};