#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(int l,int r,int mid,int n,int arr[])
{
	int sz=mid-l+1;

	int x[sz+1];
	int y[r-mid+1];

	for (int i=0;i<sz;i++)
	{
		x[i]=arr[l+i];

	}

	for (int i=0;i<r-mid;i++)
	{
		y[i]=arr[mid+i+1];


	}

	x[sz]=INT_MAX;
	y[r-mid]=INT_MAX;
	int i=0,j=0;

	for (int t=l;t<=r;t++)
	{
		if (x[i]<=y[j])
		{
			arr[t]=x[i];
			i++;

		}
		else
		{
			arr[t]=y[j];

			j++;
		}
	}

	


}

void merge_sort(int l,int r,int n,int arr[])
{
	if (l==r)
		return;


	int mid = (l+r)/2;
	merge_sort(l,mid,n,arr);

	merge_sort(mid+1,r,n,arr);
	merge(l,r,mid,n,arr);

	

	//return;

}

int main ()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	merge_sort(0,n-1,n,arr);
  
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}


}
