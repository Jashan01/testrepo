#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	
	node(int d){    //constructor
		data=d;
		next=NULL;
	}
};


void InsertAtTail(node*&head,int d){
	node*p=new node(d);
	if(head==NULL){
		head=p;
	}
	else{
		node*temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=p;
	}
}


void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}	
}


istream& operator >>(istream& is,node*& head){
	int d;
	is>>d;
	while(d!=-1){
		InsertAtTail(head,d);
		is>>d;
	}
	return is;
}


ostream& operator <<(ostream& os,node*head){
	print(head);
	return os;
}


int k_last(node* head,int k){
	node*fast=head,*slow=head;
	for(int i=1;i<=k;i++)
	fast=fast->next;
	while(fast!=NULL){
		slow=slow->next;
		fast=fast->next;
	}
	return slow->data;
}


int main(){
	node* head=NULL;
  
  // taking input for link list
	cin>>head;
	int k;   cin>>k;
  
	int p=k_last(head,k);
  //printing kth last element
	cout<<p;
	return 0;
}
