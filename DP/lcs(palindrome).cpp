#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/longest-palindromic-substring/

string reve(string s) {

	reverse(s.begin(), s.end());

	return s;
}

string palindrome(string a, string b) {

	int n = a.length();
	int m = b.length();

	int t[n + 1][m + 1];

	memset(t, 0, sizeof(t));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
			else t[i][j] = 0;
		}
	}

	// int i = n;
	// int j = m;
	// string res = "";

	// while (i > 0 && j > 0) {
	// 	if (a[i - 1] == b[j - 1]) {
	// 		res += a[i - 1];
	// 		i--;
	// 		j--;
	// 	}
	// 	else {
	// 		if (t[i][j - 1] > t[i - 1][j]) j--;
	// 		else i--;
	// 	}
	// }

	// return res;

	for(int i=0;i<n+1;i++){
		for(int j =0;j<m+1;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	return "";
}

int main() {

	string s = "aacabdkacaa";
	// "aca"
	// string s  = "abc";

	string rev = reve(s);

	// cout<<s<<" "<<rev<<endl;

	cout << palindrome(s, rev) << endl;

	return 0;
}