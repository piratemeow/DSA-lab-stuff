#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Lamuto's Partition

void quick_sort(int arr[],int l, int r)
{
	if (l>=r)
	{
		return;
	}

	int pivot = arr[r];

	int i=l;
	for (int j=l;j<=r-1;j++)
	{
		if (arr[j]<=pivot)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	
	swap(arr[i],arr[r]);


	quick_sort(arr,l,i-1);
	quick_sort(arr,i+1,r);


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

	quick_sort(arr,0,n-1);


	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
