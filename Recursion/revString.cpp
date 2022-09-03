#include <bits/stdc++.h>
using namespace std;
void reverse(string s){
	if(s.length() == 0){
		return;
	}

	string ros = s.substr(1);
	reverse(ros);
	cout<<s[0];
}

void replacePi(string s){
	if(s.length() == 0) return;
	if(s.length() == 1){
		cout<<s[0];
		return;
	}
	string ros;
	if(s[0]=='p' and s[1]=='i') {
		cout<<"3.14";
		 ros = s.substr(2); 
	}
	else {
		cout<<s[0];
		ros = s.substr(1);
	}

	replacePi(ros);

}

int main(){
	string s="binod";
	string pi = "pippxxppiixipi"; 

	replacePi(pi);
	return 0;
}