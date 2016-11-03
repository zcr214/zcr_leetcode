//2. Add Two Numbers
//You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8

#include <vector>
#include <iostream>
using namespace std;
class Solution {

public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head;
		ListNode *current = new ListNode(0);
		head = current;
		int cary = 0;

		while (l1 || l2){
			current->val = cary;
			if (l1){
				current->val += l1->val;
				l1 = l1->next;
			}
			if (l2){
				current->val += l2->val;
				l2 = l2->next;
			}
			cary = current->val / 10;
			current->val %= 10;
			if (l1 || l2 || cary > 0){
				current->next = new ListNode(cary);
				current = current->next;
			}
		}
		return head;
	}
	
	void test()
	{
		ListNode *l1 = new ListNode(2);
		ListNode *l11 = new ListNode(4);
		ListNode *l12 = new ListNode(3);
		l11->next = l12;
		l1->next = l11;

		ListNode *l2 = new ListNode(5);
		ListNode *l21 = new ListNode(6);
		ListNode *l22 = new ListNode(4);
		l21->next = l22;
		l2->next = l21;

		ListNode* result = this->addTwoNumbers(l1, l2);
		while (result)
		{
				cout << result->val << endl;
				result = result->next;
		}
		
		system("pause");
	}
};