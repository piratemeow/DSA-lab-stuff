#include <bits/stdc++.h>
using namespace std;



class node {
public:
	int data;
	node* prev;
	node* next;

	node ()
	{
		this->data = 0;
		this->prev = NULL;
		this->next = NULL;
	}

	node (int x)
	{
		this->data = x;
		this->prev = NULL;
		this->next = NULL;
	}

};





node* inset_begin(node* head,int x)
{
	node* ptr = new node();
	if (head == NULL)
	{
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->data = x;
		head = ptr;
	}
	else
	{
		ptr->data = x;
		ptr->prev = NULL;
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
	}


	return head;
}


node* rand_insert(node* head,int x,int loc)
{
	node* ptr = new node();

	node* temp = new node();

	temp = head;

	if (head == NULL)
	{
		ptr->data = x;
		ptr->next = NULL;
		head = ptr;
	}

	else
	{
		temp = head;
		for (int i=0;i<loc;i++)
		{
			temp = temp->next; 
		}

		ptr->data = x;
		ptr->next = temp->next;
		ptr->prev = temp;
		temp->next = ptr;
		temp->next->prev = ptr;

	}

	return head;
}


node* last_insert(node* head,int x)
{
	node* ptr = new node();
	node* temp = new node();
	if (ptr==NULL)
	{
		cout<<"Can't take data to list\n";
	}

	else
	{

		if (head == NULL)
		{
			ptr->data = x;
			ptr->next = NULL;
			ptr->prev = NULL;
			head = ptr;
		}
		else
		{
			temp = head ;
			while (temp->next != NULL)
			{
				temp=temp->next;
			}

			ptr->data = x;
			ptr->next = NULL;
			ptr->prev = temp; 
			temp->next = ptr;
		}
	}

	return head;
}


node* dele_begin(node* head)
{
	node* ptr = new node();
	if (head == NULL)
	{
		cout<<"Nothing to delete\n";
	}

	else
	{
		ptr = head;
		head = ptr->next;
		head->prev = NULL;
		free(ptr);
	}

	return head;
}

void rand_dele(node* head,int loc)
{
	node* ptr = new node();
	node* temp = new node();

	temp = head;
	ptr = temp;
	if (head == NULL)
	{
		cout<<"Nothing to delete\n";
	}

	else
	{
		for (int i=0;i<loc;i++)
		{
			ptr = temp;
			temp = temp->next;
		}

		ptr->next = temp->next;
		temp->next->prev = ptr;
		free(temp);
	}

	return;
}

void last_dele(node* head)
{
	node* ptr = new node();
	node* temp = new node();

	temp = head;
	ptr = temp;

	if (head == NULL)
	{
		cout<<"Nothing to delete\n";
		return;
	}
	else if (temp->next == NULL)
	{
		head = NULL;
		free(temp);
	}
	else
	{
		
		while (temp->next != NULL)
		{
			ptr = temp;
			temp = temp->next;
		}
		ptr->next = NULL;
		free(temp);
	}

	return;
}

void search(node* head,int x)
{
	node* ptr = new node();

	ptr = head;
	int i = 0;
	if (head == NULL)
	{
		cout<<"List is empty\n";
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->data == x)
			{
				cout<<"Element found at index "<<i<<endl;
				return;
			}

			ptr = ptr->next;

			i++;
		}
	}

	cout<<"Element doesn't exist\n";
	return;
}

void display(node* head)
{
	node* ptr= new node();

	ptr=head;

	while (ptr!=NULL)
	{
		cout<<ptr->data<<" ";

		ptr=ptr->next;
	}

	

	return;
}
int main ()
{
	int n;
	cin>>n;
	node* head = NULL;
	while (n--)
	{
		int x;
		cin>>x;

		head = last_insert(head,x);

	}
	//last_dele();
	display(head);
	cout<<endl;
	head = dele_begin(head);
	last_dele(head);
	display(head);

	search(head,17);

}
