#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

class linked_list
{
private:
	node *head;
public:
	linked_list()
	{
		head = NULL;
	}
	void add_end(int n);
	void display();
	void add_begin(int n);
	void add_at_position(int n, int pos);
	void delete_begin();
	void delete_end();
	void delete_at_position(int n);
	void search(int data);
	void delete_duplicate(int data);
	void display_middle();
	void reverse();
};

void linked_list::add_end(int n){
	node *temp= new node;
	temp -> data =n;
	temp -> next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else{
		node *ptr = head;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		ptr -> next = temp;
	}
}

void linked_list::add_begin(int n){
	node *temp= new node;
	temp -> data =n;
	temp -> next = NULL;
	temp -> next = head;
	head = temp;
}

void linked_list::add_at_position(int n, int pos)
{
	if(head == NULL)
	{
		cout<<"LL Empty list"<<endl;
		return;
	}
	if(pos==1)
	{
		add_begin(n);
		return;
	}
	node *temp = new node;
	temp -> data = n;
	temp -> next = NULL;

	node *ptr = head;
	int c=1;
	while(c<pos-1)
	{
		ptr = ptr -> next;
		c++;
	}
	temp -> next = ptr -> next;
	ptr -> next = temp;
}

void linked_list::display()
{
    node *ptr = head;
	while(ptr -> next != NULL)
	{
		cout<<ptr->data<<endl;
		ptr = ptr -> next;
	}
	cout<<ptr->data<<endl;
}

void linked_list::delete_begin()
{
	node* ptr=head;
	head=head->next;
	delete(ptr);
	ptr=NULL;
}

void linked_list::delete_end()
{
	node *ptr=head;
	while((ptr->next)->next != NULL)
	{
		ptr = ptr->next;
	}
	delete(ptr->next);
	ptr->next = NULL;
}

void linked_list::delete_at_position(int n)
{
	if(n==1)
	{
		delete_begin();
		return;
	}
	node *ptr = head;
	for(int i=1;i<n-1;i++)
	{
		ptr = ptr->next;
	}
	node *temp=ptr->next;
	if(temp->next == NULL)
	{
		delete_end();
		return;
	}
	ptr->next=temp->next;
	delete(temp);
	temp=NULL;
}

void linked_list::search(int data)
{
	if(head->data==data)
	{
		cout<<"Node found at position 1"<<endl;
		return;
	}
	node *ptr = head;
	int pos=1;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		pos++;
		if(ptr->data == data)
			break;
	}
	if(ptr->next == NULL && ptr->data!=data)
	{
		cout<<"Node not found"<<endl;
		return;
	}
	cout<<"Node found at position "<<pos<<endl;
}

void linked_list::delete_duplicate(int data)
{
	node *ptr = head;
	while(head->data==data)
	{
		ptr = ptr->next;
		delete_begin();
	}
	while(ptr->next != NULL)
	{
		if((ptr->next)->data == data)
		{
			node *temp=ptr->next;
			ptr->next=temp->next;
			delete(temp);
			temp=NULL;
		}
		if(ptr->next != NULL && (ptr->next)->data != data)
			ptr = ptr->next;
	}
	if(ptr->data == data)
	{
		delete_end();
	}
}

void linked_list::display_middle()
{
	if(head == NULL)
	{
		cout<<"List is Empty"<<endl;
		return;
	}
	node *slow=head;
	node *fast=head;
	while(fast!=NULL && fast->next != NULL)
	{
		fast=(fast->next)->next;
		slow=slow->next;
	}
	cout<<"Middle node is "<<slow->data<<endl;
}

void linked_list::reverse()
{
	node *ptr = head;
	node *first=head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		add_begin(ptr->data);
	}
	first->next=NULL;
	first=NULL;
}
int main(){
	int data;
	int pos;
	linked_list list;
	 cout<<"Enter data"<<endl;
	 for(int i=1;i<=7;i++)
	 {
	 	cin>>data;
	 	list.add_end(data);
	 }
	cout<<"List is"<<endl;
	list.display();
    cout<<"Enter the position to add data and data at that positon"<<endl;
    cin>>pos;
    cin>>data;
    list.add_at_position(data,pos);
    list.display();
    // cout<<"Enter the position to remove data"<<endl;
    // cin>>pos;
    // list.delete_at_position(pos);
    // cout<<"List is"<<endl;
    // list.display();
    // cout<<"Enter data to search"<<endl;
    // cin>>data;
    // list.search(data);
 //    cout<<"Enter data to delete duplicate"<<endl;
 //    cin>>data;
 //    list.delete_duplicate(data);
 //    cout<<"List is"<<endl;
	// list.display();
	// cout<<"Reversing"<<endl;
	// list.reverse();
	// list.display();

}
