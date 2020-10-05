struct node{
	int data;
	node *prev;
	node *next;
}

class doubly_ll{
	node *start;
public:
	doubly_ll(){
		start = NULL;
	}
	void add_begin(int n);
}

void doubly_ll::add_begin(int n)
{
	if(start==null)
	{
		start->data = n;
		start->prev = NULL;
		start->next = NULL;
	}
	else
	{
		node *ptr = NULL;
		ptr->data = n;
		ptr->prev = NULL;
		ptr->next = start;
		start->prev=ptr;
		start=ptr; 
	}
}

int main()
{
	int data,i;
	doubly_ll list;
	cout<<"Enter data"<<endl;
	for(i=1;i<=5;i++)
	{
		
	}
}