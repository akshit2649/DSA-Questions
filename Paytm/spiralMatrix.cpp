#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
	int top = 0;
	int bottom = r - 1;
	int left = 0;
	int right = c - 1;
	int dir = 0;
	//0 right
	//1 down
	//2 left
	//3 up


	vector<int> v;

	while (top <= bottom && left <= right) {
		if (dir == 0) {
			for (int i = left; i <= right; i++) {
				v.push_back(matrix[top][i]);
			}
			top++;
		}

		else if (dir == 1) {
			for (int i = top; i <= bottom; ++i) {
				v.push_back(matrix[i][right]);
			}
			right--;
		}

		else if (dir == 2) {
			for (int i = right; i >= left; --i)
			{
				v.push_back(matrix[bottom][i]);
			}
			c--;
			bottom--;
		}

		else if (dir == 3) {
			for (int i = bottom; i >= top; --i)
			{
				v.push_back(matrix[i][left]);
			}
			left++;
		}

		dir = (dir + 1)%4;
	}

	return v;
}

int main() {
	int r = 4;
	int c = 4;

	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	vector<int> ans = spirallyTraverse(matrix, r, c);

	for (auto it : ans) {
		cout << it << " ";
	}

	cout << endl;

	return 0;
}