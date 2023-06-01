#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void quick_sort(int l, int r, int n, int arr[])
{
	if (l>=r)
		return ;

	int start = l;
	int end = r;
	int pivot = l+(r-l)/2;

	while (start<=end)
	{
		while(arr[start]<arr[pivot])
		{
			start++;
		}
		while(arr[end]>arr[pivot])
		{
			end--;
		}

		if (start<=end)
		{
			swap(arr[start],arr[end]);
			start++;
			end--;
		}
	}


	quick_sort(l,end,n,arr);
	quick_sort(start,r,n,arr);
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

	quick_sort(0,n-1,n,arr);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
