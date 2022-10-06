#include <bits/stdc++.h>
using namespace std;

bool check(Node* T, Node* S) {
	if (!T || !S) return T == S;
	return T->data == S->data && (check(T->left, S->left) && check(T->right, S->right));
}
bool isSubTree(Node* T, Node* S)
{
	if (check(T, S)) return true;
	if (!T) return false;
	return isSubTree(T->left, S) || isSubTree(T->right, S);
}

int main() {
	return 0;
}