#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

class circular_ll{
	node *start;
public:
	circular_ll()
	{
		start=NULL;
	}
	void add_begin(int n);
	void add_end(int n);
	void display();
	void display2();
	void add_at(int n,int pos);
	void delete_begin();
	void delete_end();
	void delete_at(int pos);
	bool search(int n);
};

void circular_ll::add_begin(int n){
	node *ptr=new node;
	ptr->data=n;
	ptr->next=NULL;
	if(start==NULL)
	{
		start=ptr;
		start->next=start;
		return;
	}
	ptr->next=start->next;
	start->next=ptr;
}

void circular_ll::add_end(int n){
	node *ptr=new node;
	ptr->data=n;
	ptr->next=NULL;
	if(start==NULL)
	{
		start=ptr;
		start->next=start;
		return;
	}
	ptr->next=start->next;
	start->next=ptr;
	start=ptr;
}

void circular_ll::add_at(int n,int pos){
	node *ptr=start;
	for(int i=1;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr==start)
		{
			add_end(n);
			return;
		}
	}
	node *temp=new node;
	temp->data=n;
	temp->next=NULL;
	temp->next=ptr->next;
	ptr->next=temp;
}

void circular_ll::display()
{
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	node *ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
		cout<<ptr->data<<endl;
	}
	cout<<start->data<<endl;
}

void circular_ll::display2()
{
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	node *ptr=start;
	do
	{
		ptr=ptr->next;
		cout<<ptr->data<<endl;
	}
	while(ptr!=start);
	cout<<start->next->data<<endl;
}

void circular_ll::delete_begin(){
	if(start->next==start)
	{
		start=NULL;
		return;
	}
	node *ptr=start->next;
	start->next=ptr->next;
	delete(ptr);
	ptr=NULL;
}

void circular_ll::delete_end(){
	if(start->next==start)
	{
		start=NULL;
		return;
	}
	node *ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	delete(start);
	start=NULL;
	start=ptr;
}

void circular_ll::delete_at(int pos){
	node *ptr=start;
	for(int i=1;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr->next==start)
		{
			delete_end();
			return;
		}
	}
	node *temp=ptr->next;
	ptr->next=temp->next;
	delete(temp);
	temp=NULL;
}

bool circular_ll::search(int n){
	node *ptr=start;
	while(ptr->next!=start)
	{
		if(ptr->data==n)
		{
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}

int main()
{
	int data;
	circular_ll list;
	cout<<"Enter data"<<endl;
	for(int i=1;i<=5;i++)
	{
		cin>>data;
		list.add_end(data);
	}
	cout<<"List is"<<endl;
	list.display();
	// cout<<"Enter Position and data to add"<<endl;
	// int pos;
	// cin>>pos;
	// cin>>data;
	// list.add_at(data,pos);
	// cout<<"List is"<<endl;
	// list.display();
	// cout<<"Enter position to delete"<<endl;
	// int pos;
	// cin>>pos;
	// list.delete_at(pos);
	// cout<<"List is"<<endl;
	// list.display();

	cout<<"Enter value to search"<<endl;
	cin>>data;
	if(list.search(data))
	{
		cout<<"Value present"<<endl;
	}
	else
	{
		cout<<"Value not present"<<endl;
	}
}