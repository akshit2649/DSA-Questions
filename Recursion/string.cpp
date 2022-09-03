#include <bits/stdc++.h>
using namespace std;

string move(string s){
	if(s.length() == 0) return "";

	char ch = s[0];

	string ans = move(s.substr(1));

	if(ch == 'x') return ans+ch;
	return ch+ans;
}

void subString(string p, string up){
	if(p.length() == 0){
		cout<<up<<endl;
		return;
	}
	char ch = p[0];
	string ros = p.substr(1);

	subString(ros, up);
	subString(ros, up+ch);
}

int main(){
	string s = "axxbdxcefxhix";
	string ans = move(s);

	string a = "ABC";
	// cout<<ans<<endl;
	subString(a, "");
return 0;	
}