#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *pre = head;
		ListNode *next = head->next;

		while (next != NULL) {
			if (pre->val == next->val) {
				pre->next = next->next;
				delete next;
				next = pre->next;
			} else {
				pre = pre->next;
				next = pre->next;
			}
		}

		return head;
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->deleteDuplicates(n1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
