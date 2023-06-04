#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main ()
{
	int n;
	cin>>n;
	int k=INT_MIN;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		k=max(k,arr[i]);

	}

	int d = floor(log10(k))+1;

	int ans [n+1];
	int j=1;

	while (j<=d)
	{
		int count[10];
		memset(count,0,sizeof count);

		for (int i=0;i<n;i++)
		{
			count[(arr[i]%((int)pow(10,j)))/(int)(pow(10,j-1))]++;
		}

		for (int i=1;i<=10;i++)
		{
			count[i]+=count[i-1];
		}

		for (int i=n-1;i>=0;i--)
		{

			
			ans[count[(arr[i]%((int)pow(10,j)))/(int)(pow(10,j-1))]]=arr[i];
			
			count[(arr[i]%((int)pow(10,j)))/(int)(pow(10,j-1))]--;

		}
		for (int i=0;i<n;i++)
		{
			arr[i]=ans[i+1];
		}
		j++;
		
	}

	for (int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}

}
