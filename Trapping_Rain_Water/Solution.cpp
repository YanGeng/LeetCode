#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int trap(vector<int>& height) {
			int left = 0;
			int right = height.size() - 1;

			int leftMax = 0;
			int rightMax = 0;
			int total = 0;

			while (left < right) {
				leftMax = leftMax > height[left] ? leftMax : height[left];
				rightMax = rightMax > height[right] ? rightMax : height[right];

				if (leftMax <= rightMax) {
					total += leftMax - height[left++];
				} else {
					total += rightMax - height[right--];
				}
			}

			return total;
		}
};

int main () {
	vector<int> h;
	h.push_back(0);
	h.push_back(1);
	h.push_back(0);
	h.push_back(2);
	h.push_back(1);
	h.push_back(0);
	h.push_back(1);
	h.push_back(3);
	h.push_back(2);
	h.push_back(1);
	h.push_back(2);
	h.push_back(1);
	// 0,1,0,2,1,0,1,3,2,1,2,1

	Solution *sl = new Solution();
	int total = sl->trap(h);

	cout << "The result is: " << total << endl;

	return 0;
}
