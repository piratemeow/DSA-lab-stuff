class stac{
public:

	int* arr;
    int sz;
	int top;
	int i=0;
	stac(int sz)
	{
        arr = new int[sz];
        this->sz = sz;
		top = -1;
	}

	void push (int x)
	{
		arr[i]=x;
		i++;
	}

	void pop()
	{
		i--;
	}

	int peek()
	{
		if (i==0)
			return INT_MIN;
		else
			return arr[i-1];
	}

	bool empty()
	{
		if (i>0)
			return 0;
		else
			return 1;
	}

	bool full()
	{
		if (i==sz)
			return 1;
		else
			return 0;
	}

	void clear()
	{
		i=0;
	}

	int size()
	{
		return i;
	}


};
