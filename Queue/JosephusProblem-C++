int jos (int arr[],int n,int k)
{
    queue<int> q;
    for (int i=0;i<n;i++)
    {
        q.push(arr[i]);
    }

    while (q.size()!=1)
    {
        for (int i=1;i<k;i++)
        {
            q.push(q.front());
            q.pop();
        }
        //cout<<q.front()<<" ";
        q.pop();
    }
    return q.front();

}
