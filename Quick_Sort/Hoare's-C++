#include <bits/stdc++.h>
using namespace std;

// Quick sort using Hoare's partition scheme 
// Ascending order

void quick_sort(int arr[],int l, int r)
{
	if (l>=r) 
		return;

	int piv = arr[l];
	int i = l-1;
	int j = r+1;

	while (1)
	{
		do{
			i++;
		}while (arr[i]<piv);
		
		do{
			j--;

		}while (arr[j]>piv);
		

		if (i>=j)
		{
			break;
		}
		swap(arr[i],arr[j]);
	}

	quick_sort(arr,l,j);
	quick_sort(arr,j+1,r);
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
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
