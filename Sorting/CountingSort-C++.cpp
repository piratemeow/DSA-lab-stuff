#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void counting_sort(int n,int max_ele, int arr[],int count[],int ans[])
{
		
	for (int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}

	for (int i=1;i<=max_ele;i++)
	{
		count[i]=count[i-1]+count[i];
	}

	

	for (int i=n-1;i>=0;i--)
	{
		ans[ count[arr[i]] ] = arr[i];
		count[arr[i]]--;

	}

	return ;
	
}
int main ()
{
	int n;
	cin>>n;
	int arr[n];
	int max_ele=INT_MIN;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		max_ele = max (max_ele,arr[i]);
	}
	int count[max_ele];
	memset(count,0,sizeof count);
	int ans[n+1];
	counting_sort(n,max_ele,arr,count,ans);
	for (int i=1;i<n+1;i++)
	{
		cout<<ans[i]<<endl;
	}



}
