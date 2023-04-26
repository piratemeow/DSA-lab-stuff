#include <bits/stdc++.h>
using namespace std;

//Used template for the first time
// This does not use path compression or weighted union
// This is a normal dsu implementation
template <typename t> class dsu
{
public:

	t data;
	dsu<t>* par = NULL;
	dsu<t>* child = NULL;
	dsu<t>* next = NULL;

	dsu* init(dsu<t>* head,t ele)
	{
		if (head == NULL)
		{
			dsu<t>* b = new dsu<t>();

			b->data = ele;
			b->par = b;
			head = b;
			return head;
			
		}

		else
		{
			dsu<t>*  p = head;

			while (p->next!=NULL)
			{
				p=p->next;
			}

			dsu<t>* f = new dsu<t>();
			f->data = ele;
			f->par = f;
			p->next = f;
			return head;

		}
	}

	dsu* findd(t p, t q,dsu<t>* head)
	{
		if (head == NULL)
		{
			cout<<"EMPTY\n";
			return NULL;
		}
		dsu<t>* n = head;

		while (n!=NULL && n->data!=p)
		{
			n=n->next;
		}

		dsu<t>* m = head;
		while(m!=NULL && m->data!=q)
		{
			m=m->next;
		}

		if (n==NULL || m==NULL)
			return NULL;

		while(n->par!=n)
		{
			n=n->par;
		}


		while (m->par!=m)
		{
			m=m->par;
		}

		

		if (m->data==n->data)
		{
			return m;
		}
		else
		{
			return NULL;
		}
	}

	void union_dsu(t p , t q, dsu<t>* &head)
	{
		if (head == NULL)
		{
			cout<<"EMPTY\n";
			return ;
		}
		dsu<t>* n = head;

		while (n!=NULL && n->data!=p)
		{
			n=n->next;
		}

		dsu<t>* m = head;
		while(m!=NULL && m->data!=q)
		{
			m=m->next;
		}

		if (n==NULL || m==NULL)
			return ;

		while(n->par!=n)
		{
			n=n->par;
		}


		while (m->par!=m)
		{
			m=m->par;
		}

		m->par = n;
		//return head;

	}

	void display (dsu<t>* head )
	{

		while (head!=NULL)
		{
			cout<<head->data<<' '<<head->par->data<<endl;
			head = head->next;
		}

		return;
	}

};
int main ()
{

	int n;
	cin>>n;

	dsu<int>* head = NULL;
	dsu<int>* x = new dsu<int>();

	for (int i=0;i<n;i++)
	{

		head = x->init(head,i);
	}

	//x->display(head);

	int m ;
	cin>>m;
	while (m--)
	{
		int a,b;
		cin>>a>>b;
		x->union_dsu(a,b,head);
	}


	//x->union_dsu(3,5,head);

	if (x->findd(0,7,head))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}

}
