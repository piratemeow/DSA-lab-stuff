#include <bits/stdc++.h>
using namespace std;


class que{

    int *arr;
    int fr=0,ba=0;
    int sz;
public:
    que(int sz)
    {
        arr = new int[sz];
        this->sz = sz;
    }

    void push (int x)
    {
        arr[ba]=x;
        ba++;
    }

    void pop()
    {
      
        fr++;
    }

    int front()
    {
        return arr[fr];
    }

    bool empty()
    {
        if (fr==ba)
        {
            return 1;
        }

        return 0;
    }

    bool full()
    {
        
        if (ba==sz)
            return 1;

        else
            return 0;
    }


};
int main ()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    que* q = new que(n);
    while (n--)
    {
        int x;
        cin>>x;
        q->push(x);
    }

    
    
    cout<<q->empty();
    //cout<<q->front();
}
