#include <bits/stdc++.h>
using namespace std;

// Hearp sort using the heapify teachnique
// complexity: O(nlogn)
// space complexity: O(1)
// stable: no
// in place: yes
// It works by first converting the array to the max heap and then
// swapping the first and the last elements and continuing this process
// until the array is sorted
// by creating the max heap we can sort the array in ascending order
// by creating the min heap we can sort the array in descending order

void heapify(int arr[],int n)
{
	for (int i=n/2 ;i>=1;i--)
	{
		if (2*i<=n)
		{
			int k = i;
			int j = 2*k;
			while (j<=n)
			{
				if (j+1<=n && arr[j+1]>arr[j])
				{
					j++;
				}
				if (arr[k]<arr[j])
				{
					swap(arr[k],arr[j]);
					k=j;
					j=2*k;
				}
				else
				{
					break;
				}
			}
		}
	}

	return;
}



void heap_sort(int arr[],int n)
{
	for (int i=n;i>=1;i--)
	{
		heapify(arr,i);
		swap(arr[i],arr[1]);
	}
}

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int arr[n+1];
	for (int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}

	heap_sort(arr,n);

	for (int i=1;i<=n;i++)
	{
		cout<<arr[i]<<' ';
	}


}
