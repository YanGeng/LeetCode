#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	    int uniquePaths(int m, int n) {
			if (m == 1 || n == 1)
				return 1;

			int path = uniquePaths(m-1, n) + uniquePaths(m, n-1);
			return path;
		}
};

int main() {
	Solution *sl = new Solution();

	int res = sl->uniquePaths(3, 2);

	cout << "The result is: " << res << endl;

	return 0;
}
