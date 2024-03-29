#include <bits/stdc++.h>
using namespace std;

// Heapify algorithm for Max heap
// complexity: O(n)

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

	heapify(arr,n);

	for (int i=1;i<=n;i++)
	{
		cout<<arr[i]<<' ';
	}


}
