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
	void reverseDelete(ListNode *head, int n, int &flag) {
		if (head == NULL || head->next == NULL) {
			flag++;
			return;
		}

		reverseDelete(head->next, n, flag);

		flag++;

		if (flag == n+1) {
			ListNode *tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}

		return;
	}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if  (head == NULL) {
			return head;
		}

		//if (head != NULL && head->next == NULL && n ==1)
		//	return NULL;

		int flag = 0;

		ListNode tmpHead(-1);
		tmpHead.next = head;

		reverseDelete(&tmpHead, n, flag);

		return tmpHead.next;
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(2);
//	ListNode *n3 = new ListNode(3);
//	ListNode *n4 = new ListNode(4);
//	ListNode *n5 = new ListNode(5);

//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->removeNthFromEnd(n1, 1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
