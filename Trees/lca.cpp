#include <bits/stdc++.h>
using namespace std;

bool findP(TreeNode* root, TreeNode* p, vector<TreeNode*>& one) {
	if (!root) return false;
	one.push_back(root);
	if (root == p) return true;
	if (findP(root->left, p, one) || findP(root->right, p, one)) return true;
	one.pop_back();
	return false;
}

bool findQ(TreeNode* root, TreeNode* q, vector<TreeNode*>& two) {
	if (!root) return false;
	two.push_back(root);
	if (root == q) return true;
	if (findP(root->left, q, two) || findP(root->right, q, two)) return true;
	two.pop_back();
	return false;
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* ans;
	vector<TreeNode*> one;
	vector<TreeNode*> two;

	findP(root, p, one);
	findQ(root, q, two);

	int i = 0;
	int j = 0;
	while (i < one.size() && j < two.size()) {
		if (one[i]->val == two[j]->val) {
			ans = one[i];
		}
		i++; j++;
	}

	if (i < one.size()) {
		j--;
		while (i < one.size() ) {
			if (one[i]->val == two[j]->val) {
				ans = one[i];
			}
			i++;
		}
	}
	
	if (j < two.size()) {
		i--;
		while (j < two.size()) {
			if (one[i]->val == two[j]->val) {
				ans = two[j];
			}
			j++;
		}
	}
	return ans;
}


int main() {
	return 0;
}