//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:

	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		ListNode *H = new ListNode(0);
		H->next = head;
		ListNode *pre = H;
		ListNode *temp1 = head;
		ListNode *temp2 = temp1->next;
		
		while (temp2)
		{
			pre->next = temp2;
			temp1->next = temp2->next;
			temp2->next = temp1;

			pre = pre->next->next;
			if (pre->next)
			{
				temp1 = pre->next;
			}
			else
			{
				break;
			}
			if (temp1->next)
			{
				temp2 = temp1->next;
			}
			else
			{
				break;
			}
			
		}

		return H->next;
	}
	void test()
	{
	//	ListNode *head;
		ListNode * l1 = new ListNode(1);
		ListNode * node1 = new ListNode(2);
	
		ListNode * node2 = new ListNode(3);
		
		ListNode * node3 = new ListNode(4);
		
		node2->next = node3;
		node1->next = node2;
		l1->next = node1;
		//head->next = l1;

		ListNode * result = this->swapPairs(l1);
	

		system("pause");
	}
};