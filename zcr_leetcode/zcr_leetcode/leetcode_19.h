//19. Remove Nth Node From End of List
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note :
//	 Given n will always be valid.
//	 Try to do this in one pass.

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

	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode *head1 = new ListNode(0);
		head1->next = head;
		ListNode * current = head1;
		ListNode * toRemove = current;
		for (int i = 0; i<n; i++)
		{
			current = current->next;
		}
		while (current->next)
		{
			toRemove = toRemove->next;
			current = current->next;
		}
		toRemove->next = toRemove->next->next;
		head = head1->next;
		return head;
	}
	void test()
	{

		ListNode * x = new ListNode(1);
		
		ListNode * node1 = new ListNode(2);
		x->next = node1;

		ListNode * result = this->removeNthFromEnd(x,2);


		system("pause");
	}
};