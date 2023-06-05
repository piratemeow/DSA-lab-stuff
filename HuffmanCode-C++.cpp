#include <bits/stdc++.h>
using namespace std;


class node
{
public:
	int fre;
	char ch;

	node* left=NULL;
	node* right=NULL;

	node()
	{

	}

	node(int fre)
	{
		this->fre = fre;

	}
};


class heap{
public:
	node **arr;
	int i=1;
	int sz;

	heap(int sz)
	{
		arr= new node*[sz+1];
		this->sz=sz+1;
	}


	void insert(node* n)
	{
		arr[i]=n;
		int p = i;

		while (p>1)
		{
			int j = p/2;
			if (arr[j]->fre>arr[p]->fre)
			{
				node* temp = arr[j];
				arr[j]=arr[p];
				arr[p]=temp;

				p=j;
			}
			else
				break;
		}

		i++;
	}

	node* top()

	{
		return arr[1];
	}

	void dele()
	{
		i--;
		arr[1]=arr[i];

		int p =1;
		while (2*p<i)
		{
			int j = 2*p;
			if (j+1<i && arr[j]->fre>arr[j+1]->fre)
			{
				j++;
			}

			if (arr[j]->fre<arr[p]->fre)
			{
				node* temp = arr[j];
				arr[j]=arr[p];
				arr[p]=temp;
				p=j;
			}

			else
				break;
		}
	}


	int size()
	{
		return i-1;
	}


	void display()
	{
		for (int j=1;j<i;j++)
		{
			cout<<arr[j]->fre<<endl;
		}
	}
};


class HuffmanTree{
public:

	node* build(char ch[], int freq[], int size)
	{
		node* root;
		heap *h = new heap(size);
		for (int i=0;i<size;i++)
		{
			node* n = new node();
			n->fre=freq[i];
			n->ch = ch[i];
			h->insert(n);
		}
		//h->display();

		
		while (h->size()!=1)
		{
			node* a = h->top();

			h->dele();
			node* b = h->top();
			h->dele();
			node* n = new node();
			n->fre=a->fre+b->fre;
			
			n->ch = '!';
			n->left = a;
			n->right = b;
			h->insert(n);
		}

		//cout<<h->top()->fre<<endl;
		return h->top();
	}

	void displayCode(node* h,int code[],int i)
	{
		//cout<<h->ch<<" ";
		if (h->left)
		{

			code[i]=0;
			displayCode(h->left,code,i+1);
		}
		if (h->right)
		{

			code[i]=1;
			displayCode(h->right,code,i+1);
		}

		if (h->left==NULL && h->right ==NULL)
		{
			cout<<h->ch<<" ";
			for (int j=0;j<i;j++)
			{
				cout<<code[j];
			}
			cout<<endl;
			
		}
		
		return;
	}

	
};

int main ()
{
	HuffmanTree * h = new HuffmanTree;

	char ch[] = {'a','b','c','d'};
	int fre[]= {12, 14, 100, 1};
	node* root= h->build(ch,fre,4);

	int code[4]; // The size should be the same as the number of characters
	h->displayCode(root,code,0);

}
