#include<bits/stdc++.h>
using namespace std;


//Max heap
class heap
{
public:
    int* arr;
    int i = 1;
    int sz ;

    heap (int sz)
    {
        arr = new int[sz+1];

        this->sz = sz+1;
    }


    void insert(int ele)
    {

        if (i==sz)
        {
            cout<<"Heap is full\n";
            return;
        }

        arr[i]=ele;

        int p = i;
        i++;
        while (p>1)
        {
            int pr = p/2;
            if (arr[p]>arr[pr])
            {
                swap(arr[pr],arr[p]);
                p=pr;
            }
            else
                break;
        }

        return;
    }

    int peek()
    {
        if (i==1)
        {
            cout<<"Nothing to peek. The heap is empty\n";
            return 0;
        }
        else
            return arr[1];
    }


    void pop()
    {
        
        if (i==1)
        {
            cout<<"Empty\n";
            return;
        }
        i--;
        arr[1]=arr[i];

        int p = 1;

        while (2*p<i)
        {
            int j = 2*p;

            if (j+1>=i)
            {

                if (arr[j]>arr[p])
                {
                    swap(arr[j],arr[p]);
                    p=j;
                }
                else
                    break;
            }
            else if (arr[j]<=arr[j+1])
            {

                if (arr[j+1]>arr[p])
                {
                    swap(arr[j+1],arr[p]);
                    p=j+1;
                }

                else
                    break;
            }
            else if (arr[j]>arr[j+1])
            {
                if (arr[j]>arr[p])
                {
                    swap(arr[j],arr[p]);
                    p=j;
                }

                else
                    break;

            }
            else 
                break;
        }

        return;
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

    bool full()
    {
        if (i==sz)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


    void display()
    {
        for (int j=1;j<i;j++)
        {
            cout<<arr[j]<<" ";
        }
    }

};

int main ()
{

    int n;
    cin>>n;
    int arr[n];

    heap*  h = new heap(n);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];

        h->insert(arr[i]);

    }

    
    h->display();
    cout<<endl;
    //cout<<h->peek();
   
      h->pop();
    cout<<h->peek()<<endl;
    h->display();


}
