#include <bits/stdc++.h>
using namespace std;


// 1 based indexing
class bst{
public:
	int* arr;
	int* level;

	int i = 1;
	int sz = 0;

	bst(int sz)
	{
		arr = new int[sz+1];
		level = new int[sz+1];
		memset(level,0,sizeof level);

		for (int i=0;i<=sz;i++)
		{
			arr[i] = INT_MIN;
		}

		this->sz = sz+1;

	}

	void insert(int ele)
	{
		

		if (i==1)
		{
			arr[i]=ele;
			i++;
			return;
		}

		else
		{
			int p = 1;

			while (p<sz && arr[p]!=INT_MIN)
			{
				if (ele<=arr[p])
				{
					p=2*p;
				}

				else
				{
					p=2*p+1;
				}
			}

			arr[p]=ele;
			level[p]=level[p/2]+1;


			return;

		}
	}

	void inorder_insert(int brr[],int l,int r)
	{
		if (l>r)
			return;

		int mid = (l+r)/2;
		insert(brr[mid]);

		inorder_insert(brr,l,mid-1);
		inorder_insert(brr,mid+1,r);
	}

	bool search(int ele)
	{
		int par = 1;
		while (par<sz && arr[par]!=INT_MIN)
		{
			if (ele==arr[par])
			{
				cout<<"Element exists\n";
				return true;
			}
			else if (ele<arr[par])
			{
				par = 2*par;
			}
			else
			{
				par = 2*par+1;
			}
		}

		cout<<"The Element does not exist\n";
		return false;
	}


	void dele(int ele)
	{
		if (!search(ele))
		{
			
			return;
		}
		int par = 1;
		int node;
		while (par<sz && arr[par]!=INT_MIN)
		{
			if (ele==arr[par])
			{
				node = par;
				break;
			}
			else if (ele<arr[par])
			{
				par = 2*par;
			}
			else
			{
				par = 2*par+1;
			}
		}

		if (arr[2*node]==INT_MIN && arr[2*node+1]==INT_MIN)
		{

			arr[node] = INT_MIN;
		}

		else 
		{
			
			if (arr[2*node]!=INT_MIN && arr[2*node+1]!=INT_MIN)
			{
				
				int par = 2*node+1;
				while (arr[2*par]!=INT_MIN)
				{
					par = 2*par;
				}

				swap(arr[node],arr[par]);
				arr[par]=INT_MIN;
			}
			else
			{
				
				if(arr[2*node]!=INT_MIN)
				{

					// int par = 2*node;
					// int f = node;
					// swap(arr[par],arr[node]);

					// while (2*par<sz && 2*par+1<sz && arr[2*par+1]==INT_MIN && arr[2*par]!=INT_MIN)
					// {
					// 	swap(arr[f],arr[par]);
					// 	f=par;
					// 	par = 2*par;
					// }

					// if (arr[2*par+1]!=INT_MIN)
					// {

					// 	int k = 2*par+1;
					// 	while(2*k<sz && arr[2*k]!=INT_MIN)
					// 	{
					// 		k = 2*k;
					// 	}
					// 	cout<<arr[par]<<" "<<arr[k]<<endl;

					// 	swap(arr[k],arr[par]);
					// 	arr[k]=INT_MIN;
					// }
					// else
					// {
					// 	arr[par]=INT_MIN;

					// }


					bool flag = 1;
					int par = node;
					while (2*par+1<sz && arr[2*par+1]==INT_MIN && arr[2*par]!=INT_MIN)
					{

						par = 2*par;
					}

					if (2*par+1<sz && arr[2*par+1]!=INT_MIN)
					{

						int f = 2*par+1;
						int k = f;

						while (f<sz && arr[f]!=INT_MIN)
						{
							k=f;
							f=2*f+1;
						}


						swap(arr[node],arr[k]);
						arr[k]=INT_MIN;

					}
					else
					{
						int f = node;
						while (f<sz && arr[f]!=INT_MIN)
						{
							arr[f]=arr[2*f];
							f=2*f;
						}
					}

				}
				else
				{
					int par = 2*node+1;
					while (2*par<sz && arr[2*par]!=INT_MIN)
					{
						par = 2*par;
					}

					swap(arr[node],arr[par]);
					arr[par]=INT_MIN;
					
				}
			}
		}

	}


	int height(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)
			return 0;
		int left = height(2*par)+1;
		int right = height(2*par+1)+1;
		
		return max (left,right);
	}


	void inorder(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)

			return;

		inorder(2*par);
		cout<<arr[par]<<" ";
		inorder(2*par+1);

	}
	void preorder(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)

			return;
		cout<<arr[par]<<" ";

		preorder(2*par);
		
		preorder(2*par+1);

	}
	void postorder(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)

			return;

		postorder(2*par);
		
		postorder(2*par+1);
		cout<<arr[par]<<" ";

	}

	bool isfull(int par)
	{
		if (par>=sz || arr[par]==INT_MIN )
		{
			return 1;
		}

		if (2*par+1<sz && 2*par<sz && ((arr[2*par]!=INT_MIN && arr[2*par+1]==INT_MIN)||(arr[2*par]==INT_MIN && arr[2*par+1]!=INT_MIN)))
		{
			//cout<<arr[2*par]<<" "<<arr[2*par+1]<<endl;

			return 0;
		}

		if (2*par+1<sz && 2*par<sz &&  arr[2*par]!=INT_MIN && arr[2*par+1]!=INT_MIN)
		{

			return isfull(2*par)&isfull(2*par+1);
		}

		return 1;

	}

	bool isperfect(int par,int h)
	{
		// if (par>=sz || arr[par]==INT_MIN)
		// 	return 1;
		if (arr[2*par]==INT_MIN && arr[2*par+1]==INT_MIN)
		{
			if (level[par]==h-1)
				return 1;
			return 0;
		}

		if (arr[2*par]!=INT_MIN || arr[2*par+1]!=INT_MIN)
			return 0;

		return isperfect(2*par,h)&isperfect(2*par+1,h);

	}

	bool isbalanced(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)
			return 1;

		int left = height(2*par);
		int right = height(2*par+1);
		

		if (abs(left-right)>1)
			return 0;
		return isbalanced(2*par)&isbalanced(2*par+1);
	}

	bool iscomplete(int par)
	{
		if (par>=sz || arr[par]==INT_MIN)
			return 1;

		if (2*par<sz && 2*par+1<sz && arr[2*par]==INT_MIN && arr[2*par+1]!=INT_MIN)
			return 0;

		return iscomplete(2*par)&iscomplete(2*par+1);
	}

	bool isleft(int par)
	{

		if (par>=sz || arr[par]==INT_MIN )
		{
			return 1;
		}

		if (2*par+1<sz && arr[2*par+1]!=INT_MIN)
		{
			return 0;
		}

		return isleft(2*par);

	}

	

	bool isright(int par)
	{
		

		if (par>=sz || arr[par]==INT_MIN)
		{
			return 1;
		}

		if (2*par<sz && arr[2*par]!=INT_MIN)
		{
			return 0;
		}

		return isright(2*par+1);

	}



};


int main ()
{

	int n;
	cin>>n;
	bst* x = new bst((int)pow(2,n));

	while (n--)
	{
		int a;
		cin>>a;
		x->insert(a);
	}


	//x->inorder(1);
	x->dele(2000);
	x->inorder(1);
	cout<<endl;
	x->preorder(1);

	if (x->isleft(1))
	{
		cout<<"Left skewed\n";
	}
	else
	{
		cout<<"Not left skewed\n";
	}

	if (x->isright(1))
	{
		cout<<"Right skewed\n";
	}
	else
	{
		cout<<"Not right skewed\n";
	}

	if (x->isfull(1))
	{
		cout<<"The bst is full\n";
	}

	else
	{
		cout<<"The bst is not full\n";
	}

	if (x->isbalanced(1))
	{

		cout<<"The bst is balanced\n";
	}
	else
	{
		cout<<"The bst is not balanced\n";
	}

	if (x->isperfect(1,x->height(1)))
	{
		cout<<"The bst is perfect\n";
	}
	else
	{
		cout<<"The bst is not perfect\n";
	}
	//cout<<x->height(1);
	


}
