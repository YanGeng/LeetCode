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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
			if (head == tail)
				return NULL;

			if (head->next == tail) {
				TreeNode *root = new TreeNode(head->val);
				return root;
			}

			ListNode *p1 = head;
			ListNode *pre = p1;
			ListNode *p2 = head;

			while (p2 != tail && p2->next != tail) {
				pre = p1;
				p1 = p1->next;
				p2 = p2->next->next;
			}

			TreeNode *root = new TreeNode(p1->val);
			root->left = sortedListToBST(head, p1);
			root->right = sortedListToBST(p1->next, tail);

			return root;
		}

		TreeNode *sortedListToBST(ListNode *head) {
			return sortedListToBST(head, NULL);
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
