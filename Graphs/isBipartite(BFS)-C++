#include <bits/stdc++.h>
using namespace std;



class node {
public:
	int data;
	node* next;

	node ()
	{
		this->data = 0;
		this->next = NULL;
	}

	node (int x)
	{
		this->data = x;
		this->next = NULL;
	}

};


node* inset_begin(node* head, int x)
{
	node* ptr = new node();

	if (ptr==NULL)
	{
		cout<<"Can't take data to list\n";

		return head;
	}

	else
	{
		if (head == NULL)
		{
			head = new node();
			head->data = x;
		}
		else
		{
			ptr->data = x;
			ptr->next = head;
			head = ptr;
		}
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
		return head;
	}

	else
	{
		temp = head;
		for (int i=0;i<loc-1;i++)
		{
			temp = temp->next; 
		}

		ptr->data = x;
		ptr->next = temp->next;
		temp->next = ptr;

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
			head = ptr;

			return head;
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
		free(temp);
	}

	return ;
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

class que{

    int *arr;
    int fr=0,ba=0;
    int sz;
public:
    que(int sz)
    {
        arr = new int[sz];
        this->sz = sz;
    }

    void push (int x)
    {
        arr[ba]=x;
        ba++;
    }

    void pop()
    {
      
        fr++;
    }

    int front()
    {
        return arr[fr];
    }

    bool empty()
    {
        if (fr==ba)
        {
            return 1;
        }

        return 0;
    }

    bool full()
    {
        
        if (ba==sz)
            return 1;

        else
            return 0;
    }


};

int n;
int sequence[10000];
int level[10000];

bool isBipartite(node* v[],int n, int ver,int visi[],int color[])
{
	que* q = new que(n+1);

	q->push(ver);
	visi[ver]=1;
	int i=0;
	sequence[i]=ver;
	i++;
	level[ver] = 0;
	

	while (!q->empty())
	{
		int cur = q->front();
		q->pop();
		node* x = v[cur];
		//color[cur] = 1;

	
		while (x!=NULL)
		{
			if (visi[x->data]==0)
			{
				visi[x->data]=1;
				q->push(x->data);
				
				sequence[i]=x->data;
				i++;

				level[x->data]=level[cur]+1;
				color[x->data] = ~color[cur];
			}
			if (color[x->data]==color[cur])
			{
				return false;
			}
			
			x=x->next;
		}


	}

	return true;
}
int main ()
{
	// int n;
	// cin>>n;
	// node* head = NULL;
	// while (n--)
	// {
	// 	int x;
	// 	cin>>x;

	// 	head = last_insert(head,x);

	// }

	// last_insert(head,0);
	// rand_insert(head,-1,9);
	// rand_dele(head,9);
	// last_dele(head);
	// display(head);

	// search(head,11);

	
	cin>>n;
	int m;
	cin>>m;

	node* v[n+1];

	for (int i=0;i<n+1;i++)
	{
		v[i]=NULL;
	}

	while (m--)
	{
		int a,b;
		cin>>a>>b;
		
		v[a] = last_insert(v[a],b);
		v[b] = last_insert(v[b],a);
	}


	int visi[n+1];
	int color[n+1];
	memset(visi,0,sizeof visi);
	memset(color,0,sizeof color);

	if(isBipartite(v,n,1,visi,color))
		cout<<"The graph is bipartite\n";
	else
		cout<<"The graph is not bipartite\n";


	for (int i=0;i<n;i++)   //Displaying traversal sequence and level of vertices
	{
		cout<<sequence[i]<<" "<<level[sequence[i]]<<endl;
	}

}
