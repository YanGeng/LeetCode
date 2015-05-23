#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int m = obstacleGrid.size();
			int n = obstacleGrid[0].size();

			int path[100][100];
			if (obstacleGrid[0][0] == 0) {
				path[0][0] = 1;
			} else {
				path[0][0] = 0;
			}

			for (int i = 1; i < m; ++i) {
				if (obstacleGrid[i][0] == 0 && path[i-1][0] == 1) {
					path[i][0] = 1;
				} else {
					path[i][0] = 0;
				}
			}

			for (int j = 1; j < n; ++j) {
				if (obstacleGrid[0][j] == 0 && path[0][j-1] == 1) {
					path[0][j] = 1;
				} else {
					path[0][j] = 0;
				}
			}


			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					if (obstacleGrid[i][j] == 0) {
						path[i][j] = path[i-1][j] + path[i][j-1];
					} else {
						path[i][j] = 0;
					}
				}
			}

			return path[m-1][n-1];
		}
};

int main() {
	Solution *sl = new Solution();

	//int res = sl->uniquePaths(3, 2);

	//cout << "The result is: " << res << endl;

	return 0;
}
