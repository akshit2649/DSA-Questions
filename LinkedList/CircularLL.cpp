#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int val){
		data = val;
		next=NULL;
	}
};

void insertAtHead(node* &head, int val){
	node* n = new node(val);
	
	if(head==NULL){
		n->next = n;
		head = n;
		return;
	}

	node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = n;
	n->next = head;
	
	head = n;
}

void insertAtTail(node* &head, int val){

	if(head == NULL){
		insertAtHead(head, val);
		return;
	}

	node* n = new node(val);
	node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = n;
	n->next = head;
}

void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;	
}

int main(){
	node* head1 = NULL;
	node* head2 = NULL;
	insertAtTail(head1,1);
	insertAtTail(head2,2);
	insertAtTail(head1,3);
	insertAtTail(head2,4);
	insertAtTail(head1,5);
	insertAtTail(head2,6);
	insertAtTail(head1,9);
	insertAtTail(head2,10);

	display(head1);
	display(head2);

	node* ans = mergeRec(head1, head2);

	display(ans);

return 0;
}