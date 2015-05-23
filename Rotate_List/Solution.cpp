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
    ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0)
			return head;

		vector<ListNode *> myVec;
		ListNode *tmp = head;
		int i = 0;
		while (tmp != NULL) {
			myVec.push_back(tmp);
			i++;
			tmp = tmp->next;
		}

		int tail = myVec.size() - (k % myVec.size()) ;

		if (tail == 0 || k % myVec.size() == 0)
			return head;

		myVec[tail-1]->next = NULL;
		myVec[myVec.size()-1]->next = myVec[0];

		return myVec[tail];
    }
};

int main ()
{
	ListNode  *n1 = new ListNode(1);
	ListNode  *n2 = new ListNode(2);
	ListNode  *n3 = new ListNode(3);
	ListNode  *n4 = new ListNode(4);
	ListNode  *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *res = sl->rotateRight(n1, 2);

	ListNode *tmp = res;
	while (tmp != NULL) {
		cout << "The val is: " << tmp->val << endl;
		tmp = tmp->next;
	}

	return 0;
}
