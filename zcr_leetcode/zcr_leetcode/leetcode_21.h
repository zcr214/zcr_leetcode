//21. Merge Two Sorted Lists
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.

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

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode * head = new ListNode(0);
		ListNode * current = head;
		while (l1 || l2)
		{
			if (l1 == NULL)
			{
				current->next = l2;
				break;
			}
			if (l2 == NULL)
			{
				current->next = l1;
				break;
			}

			if (l1->val <= l2->val)
			{
				current->next = l1;
				current = current->next;
				l1 = l1->next;
			}
			else
			{
				current->next = l2;
				current = current->next;
				l2 = l2->next;
			}

		}
		return head->next;
	}
	void test()
	{

		ListNode * l1 = new ListNode(1);
		ListNode * node1 = new ListNode(3);
		l1->next = node1;

		ListNode * l2 = new ListNode(2);
		
		ListNode * result = this->mergeTwoLists(l1, l2);


		system("pause");
	}
};