#include <iostream>
#include <vector>

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
	ListNode* reverse(ListNode *head, int k, ListNode **newH, ListNode **nextH, bool &reverseFlag) {
		if (head == NULL || head->next == NULL || k == 1) {
			*nextH = head->next;
			if (k > 1)
				reverseFlag = false;
			else
				*newH = head;

			return head;
		}

		ListNode *res = reverse(head->next, k-1, newH, nextH, reverseFlag);

		if (reverseFlag) {
			res->next = head;
			head->next = NULL;
		}

		return head;
	}

    ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 1)
			return head;
		
		//ListNode tH(-1);
		ListNode *tmpHead = NULL; //&tH;
		ListNode *tmpTail = NULL; //new ListNode(-1);
		
		ListNode *newHead = new ListNode(-1);
		ListNode *newTail = newHead;
		ListNode *tmpH = head;
		bool reverseFlag = true;

		while (tmpH != NULL) {
			ListNode *t = reverse(tmpH, k, &tmpHead, &tmpTail, reverseFlag);
			if (reverseFlag) {
				newTail->next = tmpHead;
				newTail = t;
				tmpH = tmpTail;
			} else {
				newTail->next = t;
				tmpH = tmpTail;
			}
		}

		ListNode *res = newHead->next;
		delete newHead;

		return res;
    }
};

int main()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	 
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *res = sl->reverseKGroup(n1, 3);

	ListNode *tmp = res;

	while (tmp != NULL) {
		cout << "The val is: " << tmp->val << endl;
		tmp = tmp->next;
	}

	return 0;
}
