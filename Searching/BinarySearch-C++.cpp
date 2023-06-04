#include <bits/stdc++.h>
using namespace std;


//Binary search using recursion
bool binary(int arr[], int n,int l, int r, int tar)
{
	if (l>r)
	{
		return false;
	}

	int mid = (l+r)/2;


	if (arr[mid]==tar)
	{
		return true;
	}


	else if (arr[mid]>tar)

	{
		return binary(arr,n,l,mid-1,tar);
	}
	else
	{
		return binary(arr,n,mid+1,r,tar);
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

	if (binary(arr,n,0,n-1,2))
	{
		cout<<"HJ\n";
	}

	// To find the square root of n
	int l=0,r=n;
	int mid ;
	int ans = -1;

	while(l<=r)
	{
		mid=(l+r)/2;

		if (mid*mid >= n)
		{
			ans = mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}

	if (ans*ans>n)
	{
		ans--;
	}


	cout<<ans<<endl;


}
