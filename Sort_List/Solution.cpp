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
	ListNode* sort(ListNode* head, int n) {
		ListNode *newHead = new ListNode(-1);
		ListNode *newTail = newHead;

		ListNode *h1 = head;
		ListNode *h2 = head;

		ListNode *nextTail = NULL;

		int i = 0;
		while (i < n) {
			h2 = h2->next;
			i++;
		}
		int flag1 = n;
		int flag2 = n;
		while (flag1 > 0 && flag2 > 0) {
			if (h1->val > h2->val) {
				newTail->next = h1;
				h1 = h1->next;
				newTail = newTail->next;
				flag1--;
			} else {
				newTail->next = h2;
				h2 = h2->next;
				newTail = newTail->next;
				flag2--;
				if (flag2 == 0) {
					nextTail = h2;
				}
			}
		}

		if (flag1 == 0) {
			while (flag2 > 0) {
				newTail->next = h2;
				h2 = h2->next;
				newTail = newTail->next;
				flag2--;
				if (flag2 == 0) {
					nextTail = h2;
				}
			}
		} else if (flag2 == 0) {
			while (flag1 > 0) {
				newTail->next = h1;
				h1 = h1->next;
				newTail = newTail->next;
				flag1--;
			}
		}

		return nextTail;
	}

    ListNode* sortList(ListNode* head) {
		int length = 0;
		ListNode *tmp = head;
		while (tmp != NULL) {
			length++;
			tmp = tmp->next;
		}

		tmp = head;
		for (int i = 2; i < length; i = 2*i) {
			for (int j = i; j < lenth; j = j + i) {
				sort(tmp, i)
			}
		}
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(5);
	ListNode *n5 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->swapPairs(n1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
