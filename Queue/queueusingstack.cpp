#include <iostream>
#include <stack>
using namespace std;

class queue{
	stack<int> s1;
	stack<int> s2;

public:
	void push(int x){
		s1.push(x);
	}

	int pop(){
		if(s1.empty() && s2.empty()) return -1;
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}

		int topVal = s2.top();
		s2.pop();
		return topVal;
	}

	bool empty(){
		if(s1.empty() && s2.empty()) return 1;
		return -1;
	}
};

int main(){

	queue q;

	for(int i=0;i<4;i++){
		q.push(i);
	}

	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;

	return 0;
}