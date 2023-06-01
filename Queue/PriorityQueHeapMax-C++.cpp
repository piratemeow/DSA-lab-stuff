#include <bits/stdc++.h>

using namespace std;

// dequeue using max heap
class dequ{
    int* arr;
    int i=1;
    int sz;

public:

    dequ(int sz)
    {
        arr = new int[sz+1];
        this->sz = sz+1;
    }

    void insert(int ele)
    {
        if (i==sz)
        {
            cout<<"No more space left\n";
            return;
        }

        arr[i]=ele;

        int p=i;
        while (p>1)
        {
            int pr = p/2;

            if (arr[p]>arr[pr])
            {
                swap(arr[p],arr[pr]);

                p=pr;
            }

            else
                break;
        }

        i++;
    }

    int front()
    {
        if (i==1)
        {
            cout<<"Empty\n";
            return 0;
        }
        return arr[1];
    }

    void dele_front ()
    {

        if (i==1)
        {
            cout<<"There is nothing to delete\n";
            return ;
        }
        arr[1]=arr[i-1];
        i--;

        int p = 1;
        while (2*p<=i)
        {
            int j = 2*p;

            if (j+1<=i)
            {
                if (arr[j]<arr[j+1])
                    j++;
            }

            if (arr[j]>arr[p])
            {
                swap(arr[j],arr[p]);
                p=j;
            }

            else
                break;
        }

    }


    void display()
    {
        if (i==1)
        {
            cout<<"Empty\n";
            return;
        }
        for (int j=1;j<i;j++)
        {
            cout<<arr[j]<<" ";
        }

        cout<<endl;

        return;
    }

    int size()
    {
        return i-1;
    }


    bool empty()
    {
        if (i==1)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    bool full ()
    {
        if (i==sz)
            return 1;
        else
        {
            return 0;
        }
    }
};
int main ()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // int n;
    // cin>>n;

    // dequ* q = new dequ(n);
    // while (n--)
    // {
    //     int x;
    //     cin>>x;

    //     q->insert(x);

    // }

    // q->display();

    // q->dele_front();
    //  q->dele_front();
    //   q->dele_front();
    //    q->dele_front();
    //    // q->dele_front();
    // q->display();

    // cout<<q->size();


    int n;
    cin>>n;
    int arr[n];

    dequ* q = new dequ(n);
    dequ* qi = new dequ(n);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k ;
    cin>>k;

    for (int i=0;i<k;i++)
    {
        q->insert(arr[i]);
        
    }

    cout<<q->front()<<' ';

    q->dele_front();
    for (int i=k;i<n;i++)
    {
        q->insert(arr[i]);
        cout<<q->front()<<" ";
        q->dele_front();
    }



}
