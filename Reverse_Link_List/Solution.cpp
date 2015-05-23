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
		ListNode* reverseList(ListNode* head, ListNode **newHead) {
			if (head == NULL || head->next == NULL) {
				*newHead = head;
				return head;
			}

			ListNode *res = reverseList(head->next, newHead);
			
			res->next= head;
			head->next = NULL;
			return head;
		}		
};

int main ()
{
	ListNode *n0 = new ListNode(0);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;

	ListNode *tmpH = new ListNode(-1);
	ListNode **newHead = &tmpH;
	
	Solution *sl = new Solution();
	ListNode *tail = sl->reverseList(n0, newHead);

	return 0;
}
