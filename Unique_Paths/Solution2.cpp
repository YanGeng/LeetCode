#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	    int uniquePaths(int m, int n) {
			int path[100][100];
			path[0][0] = 1;
			path[1][0] = 1;
			path[0][1] = 1;

			for (int i = 0; i < m; ++i) {
				path[i][0] = 1;
			}

			for (int j = 0; j < n; ++j) {
				path[0][j] = 1;
			}

			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					path[i][j] = path[i-1][j] + path[i][j-1];
				}
			}

			return path[m-1][n-1];
		}
};

int main() {
	Solution *sl = new Solution();

	int res = sl->uniquePaths(3, 2);

	cout << "The result is: " << res << endl;

	return 0;
}
