#include <bits/stdc++.h>
using namespace std;

class cir_que{

    int *arr;
    int fr=0,ba=0;
    int he=0;
    int sz;
public:
    cir_que(int sz)
    {
        arr = new int[sz];
        this->sz = sz;
    }

    void push(int x)
    {
        if (this->full())
        {
            if (fr>=he && fr!=0)
            {
                arr[he]=x;
                he++;
                ba=he;
            }

            else
            {
                cout<<"Can't push elementn\n";
            }
        }

        else
        {
            if (ba==sz)
            {
                cout<<"This que is full\n;
            }
            arr[ba] = x;
            ba++;
        }
    }

    void pop()
    {
        fr++;
        if (fr==sz)
        {
            fr=0;
        }
    }

    int front()
    {
       return arr[fr];        
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    
    cir_que* q = new cir_que(n);
    while (n--)
    {
        int x;
        cin>>x;
        q->push(x);
        //cout<<x;
    }

    cout<<q->front()<<endl;
    q->pop();
    q->pop();
    q->push(12);
    q->push(13);
    cout<<q->front()<<endl;
    q->pop();
    q->pop();
    q->pop();
    //q->pop();
    

    cout<<q->front()<<endl;
    q->pop();
    cout<<q->front()<<endl;

    
    
    //cout<<q->empty();
    //cout<<q->front();
}
