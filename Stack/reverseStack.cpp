#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
	if(st.empty()){
		st.push(ele);
		return;
	}

	int top = st.top();
	st.pop();
	insertAtBottom(st, ele);

	st.push(top);
}

void reverse(stack<int> &st){
	if(st.empty()) return;

	int ele = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st, ele);
}

int main(){

	stack<int> s;
	for(int i=1;i<=5;i++){
		s.push(i);
	}

	reverse(s);

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
