#include<bits/stdc++.h>
using namespace std;

// Used array
// This does not use path compression or weighted union
// This is a normal dsu implementation

class dsu
{
public:

	int* id;
	int sz;

	dsu(int sz)
	{
		id = new int(sz+1);
		this->sz = sz+1;
	}

	void init()
	{
		for (int i=0;i<sz;i++)
		{
			id[i]=i;
		}
	}

	int find_root(int p)
	{
		while (id[p]!=p)
		{
			p=id[p];
		}

		return p;
	}


	bool find(int p,int q)
	{
		if (find_root(p)==find_root(q))
		{
			return 1;
		}

		else
		{
			return 0;
		}

	}


	void union_dsu(int p, int q)
	{
		int x = find_root(p);
		int y = find_root(q);

		id[x]=y;
	}

	void display()
	{
		for (int i=0;i<sz;i++)
		{
			cout<<id[i]<<" ";
		}

		cout<<endl;
	}

};
int main ()
{
	int n;
	cin>>n;

	dsu* d = new dsu(n);

	d->init();

	int m;
	cin>>m;
	while (m--)
	{
		int a,b;
		cin>>a>>b;
		d->union_dsu(a,b);
	}


	d->display();
	d->union_dsu(2,6);


	if(d->find(1,7))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
