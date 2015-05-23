#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
		ListNode* reverseList(ListNode* head, ListNode **newHead, int length, ListNode **newTail) {
			if (length <= 0 || (head == NULL || head->next == NULL)) {
				*newHead = head;
				*newTail = head->next;
				return head;
			}

			length--;

			ListNode *res = reverseList(head->next, newHead, length, newTail);
			
			res->next= head;
			head->next = NULL;
			return head;
		}		

		ListNode* reverseBetween(ListNode* head, int m, int n) {
			int length = n - m;

			if (length <= 0)
				return head;

			ListNode *nH_ = NULL;
			ListNode *tail1 = NULL;

			if (m > 1) {
				tail1 = head;
				int i = 2;
				while (i < m && tail1 != NULL && tail1->next != NULL) {
					tail1 = tail1->next;
					i++;
				}
			}

			if (tail1 != NULL) {
				nH_ = tail1->next;
			} else if (m == 1) {
				nH_ = head;
			}

			ListNode *ntmpH = new ListNode(-1);
			ListNode **newHead_ = &ntmpH;

			ListNode *ntmpT = new ListNode(-1);
			ListNode **newTail_ = &ntmpT;

			ListNode *tail2_ = reverseList(nH_, &ntmpH, length, &ntmpT);
			//ListNode *tail2_ = reverseList(nH_, newHead_, length, newTail_);

			tail2_->next = *newTail_;

			if (tail1 != NULL) {
				tail1->next = *newHead_;
				return head;
			}

			return *newHead_;

		}
};

int main ()
{
	ListNode *n0 = new ListNode(0);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode *tmpH = new ListNode(-1);
	ListNode **newHead = &tmpH;
	
	Solution *sl = new Solution();
	ListNode *tail = sl->reverseBetween(n0, 3, 4);

	ListNode *tmp = tail;
	while (tmp != NULL) {
		cout << "The val is: " << tmp->val << endl;
		tmp = tmp->next;
	}

	return 0;
}
