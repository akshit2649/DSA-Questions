#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string S) {
	unordered_map<char, int> m;
	int ans = 1;
	int i = 0;
	int j = 0;

	while (j < S.length()) {
		m[S[j]]++;

		while (!m.empty() and (m.size() < j - i + 1)) {
			if (m[S[i]] > 1) m[S[i]]--;
			else m.erase(S[i]);
			i++;
		}
		int sz = m.size();
		ans = max(ans, sz);
		j++;
	}
	return ans;
}

int longestUniqueSubsttr(string S){
    
    vector<int> dict(256,-1);
    int mx = 0; int start =-1;
    for(int i=0;i<S.length();i++){
        if(dict[S[i]]>start) start = dict[S[i]];
         dict[S[i]] = i;
        mx = max(mx, i-start);
    }
    
    return mx;
    }

int main() {

	string S = "abdefgabef";

	cout << longestUniqueSubsttr(S) << endl;

	return 0;
}