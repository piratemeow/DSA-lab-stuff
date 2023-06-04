#include <bits/stdc++.h>
using namespace std;
//Comparison based sorting

// All are in non decreasing order

//Stable in-place sort
// Best O(n) worst O(n^2)
void bubbleSort(int arr[],int n)
{
	for (int i=0;i<n;i++)
	{
		bool swapped = 0;
		for (int j=0;j<n-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped = 1;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}



//Unstable in-place sort
// Best O(n^2) worst O(n^2)
void selectionSort(int arr[],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (arr[i]>arr[j])
			{
				swap(arr[i],arr[j]);
			}
		}
	}
}


//Stable in-place sort
// Best O(n) worst O(n^2)
void insertionSort(int arr[], int n)
{
	for (int i=0;i<n;i++)
	{
		int j = i;

		while (j>0 && arr[j]<arr[j-1])
		{
			swap(arr[j],arr[j-1]);
			j--;
		}


	}
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
	insertionSort(arr,n);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
