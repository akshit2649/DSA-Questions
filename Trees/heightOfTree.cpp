#include <bits/stdc++.h>
using namespace std;

 int height(struct Node* node){
   if(node == NULL) return 0;
   int left = height(node->left) +1;
   int right = height(node->right) +1;
   return max(left, right);
 }

int main(){
	return 0;
}