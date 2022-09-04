#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node* prev;

	node(int val){
		data = val;
		next=NULL;
		prev=NULL;
	}
};

void insertAtHead(node* &head, int val){
	node* n = new node(val);
	n->next = head;
	if(head!=NULL){
		head->prev = n;
	}

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
	n->prev = temp;
}

void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;	
}

node* merge(node* &head1, node* &head2){

	node* p1 = head1;
	node* p2 = head2;

	node* dummyNode = new node(-1);

	node* p3 = dummyNode;

	while(p1!=NULL and p2!=NULL){
		if(p1->data < p2->data ){
			p3->next = p1;
			p1 = p1->next;

		}
		else{
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}

	while(p1!=NULL){
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}

	while(p2!=NULL){
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}

	return dummyNode->next;
}

node* mergeRec(node* &head1, node* &head2){

	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}

	node* result;

	if(head1->data<head2->data){
		result = head1;
		result->next = mergeRec(head1->next, head2);
	}
	else{
		result = head2;
		result->next = mergeRec(head1, head2->next);
	}


	return result;
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