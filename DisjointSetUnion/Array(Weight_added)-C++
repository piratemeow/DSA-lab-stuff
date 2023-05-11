#include<bits/stdc++.h>
using namespace std;

//Path compression and weighted union approach
// Used array
// This is a normal dsu implementation

class dsu
{
public:

	int* id;
	int* wt;
	int sz;

	dsu(int sz)
	{
		id = new int(sz+1);
		//rankk = new int(sz+1);
		wt = new int(sz+1);
		
		this->sz = sz+1;
		
	}

	void init()
	{
		for (int i=0;i<sz;i++)
		{
			id[i]=i;

			//rankk[i]=1;
		}
		memset(wt,0,sizeof(wt));
	}
	// Finding the path size for weighted union approach
	int path_size(int p)
	{
		int count = 0;
		while (id[p]!=p)
		{
			count ++;
			p=id[p];
		}

		return count;
	}


	// Path compression approach
	int find_root(int p)
	{
		if (id[p]==p)
			return p;

		return id[p] = find_root(id[p]);
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
		// int sz1 = path_size(p);
		// int sz2 = path_size(q);
		int x = find_root(p);
		int y = find_root(q);
		if (wt[x]<wt[y])
		{
			id[x]=y;
		}
		else if (wt[x]>wt[y])
		{
			id[y]=x;
		}
		else
		{
			id[x]=y;
			wt[y]++;
		}
		
		
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

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
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
