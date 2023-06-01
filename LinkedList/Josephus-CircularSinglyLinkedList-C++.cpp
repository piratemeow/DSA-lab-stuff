#include <bits/stdc++.h>

using namespace std;


class node
{
public:
	int data;
	node* next = NULL;

	node()
	{
		data = 0;
	}

	node* insert(node* head,int ele)
	{
		
		if (head == NULL)
		{
			
			
			head = new node();
			head ->data = ele;

			head->next = head;

			return head;
		}

		else
		{
			node* p = new node();
			p=head;

			while (p->next!=head)
			{
				p=p->next;
			}

			node* n = new node();
			
			n->data = ele;
			n->next = head;
			p->next = n;
			return head;
		}

		
	}

	node* dele(node* head,int loc)
	{
		if (head == NULL)
		{
			return NULL;
		}

		else
		{
			node* n = new node();
			node* par = new node();
			par = head;
			n = head;

			for (int i=0;i<loc;i++)
			{
				par = n;
				n=n->next;
			}

			par ->next = n->next;

			delete(n);

			return par->next;

		}
	}


	int size(node* head)
	{
		node* n = new node();
		n= head;

		int i = 1;
		while (n->next!=head)
		{
			n=n->next;
			i++;
		}

		return i;
	}


	void display(node* head)
	{
		node* p = head;
		
		while(p->next!=head)
		{
			cout<<p->data<<" ";
			p = p ->next;
		}
		cout<<p->data<<endl;
		{
			
		};
	}
};

int main ()
{

	int n;
	cin>>n;
	int arr[n];

	node* head = NULL;
	node* x = new node();
	for(int i=1;i<=n;i++)
	{
		
		arr[i-1]=i;
		head = x->insert(head,i);
	}

	x->display(head);

	
	int k;
	cin>>k;
	while (x->size(head)!=1)
	{
		head = x->dele(head,k-1);
	}

	cout<<head->data<<endl;


	
}
