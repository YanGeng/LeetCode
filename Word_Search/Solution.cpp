#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
	public:
	    bool exist(vector< vector<char> >& board, string word) {
			int yl = board.size();
			int xl = board[0].size();

			map<char, int> myMap;
			for (int i = 0; i < xl; ++i) {
				for (int j = 0; j < yl; ++j) {
					if (myMap.find(board[i][j]) == myMap.end()) {
						myMap[board[i][j]]++;
					} else {
						myMap.insert(make_pair(board[i][j], 1));
					}
				}
			}

			for (int i = 0; i < word.size(); ++i) {
				char tmp = word[i];
				if (myMap.find(tmp) == myMap.end()) {
					return false;
				} else {
					myMap[tmp]--;
					if (myMap[tmp] == 0) {
						myMap.erase(tmp);
					}
				}
			}

			return true;
	    }
};

int main () {
	vector< vector<char> > tmp;
	tmp[0][0] = 'a';
	tmp[0][1] = 'a';

	string word = "a";

	Solution *sl = new Solution();
	sl->exist(tmp, word);
	return 0;
}
