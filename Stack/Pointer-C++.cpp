#include <bits/stdc++.h>
using namespace std;


class stac
{
public:
    int* p=(int*)(malloc(sizeof (int)));
    int i=0;


    void push(int item)
    {
        
        
        *p = item;
       
        p++;
        i++;
    }

    void pop()
    {
        i--;
        //free(p);
        p--;
       // cout<<p[0];
        // cout<<*p<<endl;
       
       
    }

    int top()
    {
        p--;
        int x = *p;
        p++;

        return x;
        
    }
};
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    stac s;
    while (n--)
    {
        int x;
        cin>>x;
        s.push(x);
       // cout<<"f\n";
    }

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

}
