#include <bits/stdc++.h>
using namespace std;


int pre(char ch)
{
	if (ch=='^')
		return 3;
	else if (ch=='*' || ch=='/')
		return 2;

	else if (ch=='+' || ch=='-')
		return 1;
	else 
		return 0;
}
int main ()
{
	string s;
	cin>>s;



	string ans;
	stack<char> x;
	for (int i=0;i<s.size();i++)
	{
		if ((s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&& s[i]<='z')||(s[i]>='0' && s[i]<='9'))
			ans +=s[i];

		else if (s[i]=='(')
			x.push(s[i]);

		else if (s[i]==')')
		{
			while (x.top()!='(')
			{
				ans+= x.top();
				x.pop();
			}

			x.pop();

		}

		else
		{
			while (!x.empty() && pre(s[i])<=pre(x.top()))
			{
				ans += x.top();
				x.pop();
			}

			x.push(s[i]);

		}

	}

		while (!x.empty())
		{
			ans+=x.top();
			x.pop();
		}



	cout<<ans<<endl;
}
