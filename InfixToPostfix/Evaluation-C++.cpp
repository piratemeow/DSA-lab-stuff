#include<bits/stdc++.h>
using namespace std;


int main ()
{
	string s;
	cin>>s;
	stack<int> st;
	int ans = 0;


	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			st.push(s[i]-'0');
		}

		else
		{
			if (s[i]=='*')
			{
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				ans = x*y;
				char a = ans+'0';
				st.push(ans);
			}
			else if (s[i]=='/')
			{
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				ans = y/x;
				char a = ans+'0';
				st.push(ans);

			}

			else if (s[i]=='+')
			{
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				ans = x+y;
				char a = ans+'0';
				st.push(ans);
			}
			else
			{
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				ans = y-x;
				char a = ans+'0';
				st.push(ans);
			}
		}

		//cout<<st.top()<<endl;
	}

	cout<<st.top()<<endl;
}
