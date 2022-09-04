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


int length(node* head){
	int l = 0;
	node* temp = head;
	while(temp!=NULL){
		temp = temp->next;
		l++;
	}
	return l;
}

int intersection(node* &head1, node* &head2){
	int l1 = length(head1);
	int l2 = length(head2);

	int d = 0;
	node* pt1; //longer length pointer
	node* pt2; //shorter length pointer

	if(l1>l2){
		d =l1-l2;
		pt1 = head1;
		pt2 = head2;
	}
	else{
		d = l2-l1;
		pt1 = head2;
		pt2 = head1;
	}

	while(d){
	 	pt1 = pt1->next;
	 	if(pt1==NULL) return -1;
		d--;
	}

	while(pt1!=NULL and pt2!=NULL){
		if(pt1 == pt2) return pt1->data;
		pt1 = pt1->next;
		pt2 = pt2->next;
	}

	return -1;

}

void intersect(node* &head1, node* &head2, int pos){
	node* temp1 = head1;
	pos--;
	while(pos--){
		temp1 = temp1->next;
	}

	node* temp2 = head2;
	while(temp2->next!=NULL){
		temp2 = temp2->next;
	}

	temp2->next = temp1;
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
	insertAtTail(head1,2);
	insertAtTail(head1,3);
	insertAtTail(head1,4);
	insertAtTail(head1,5);
	insertAtTail(head1,6);
	insertAtTail(head2,9);
	insertAtTail(head2,10);
	intersect(head1, head2, 3);

	display(head2);


	cout<<intersection(head1, head2)<<endl;
	// cout<<"HE"<<endl;

return 0;
}