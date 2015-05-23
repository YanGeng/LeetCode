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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
			return head;
		
		ListNode *tmpHead = head;
		int flag = 0;
		ListNode *tmp[2];
		while (tmpHead != NULL) {
			int t = flag % 2;
			tmp[t] = tmpHead; 
			if (flag % 2 == 1 && flag > 0) {
				int tmpVal = tmp[0]->val;
				tmp[0]->val =tmp[1]->val;
				tmp[1]->val = tmpVal;
			}

			flag++;
			tmpHead = tmpHead->next;
		}

		return head;
    }
};

int main ()
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
	ListNode *h = sl->swapPairs(n1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
