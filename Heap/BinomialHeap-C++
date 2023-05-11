#include<bits/stdc++.h>
#define INF 987654321
#define MAX_N 100002
using namespace std;
typedef long long lld;

typedef unsigned long long llu;


struct BinNode
{
    int key;   // The data kept in the each node
    int degree; // Degree of the root

    // Sibling
    BinNode *f;

    // Parent
    BinNode *p;

    // Child : The leftmost child
    BinNode *c; 
    
    BinNode()
    {
        this -> key = 0;
        this -> degree = 0;
        this -> f = this -> p = this -> c = NULL;
    }
    
    BinNode(int key)
    {
        this -> key = key;
        this -> degree = 0;
        this -> f = this -> p = this -> c = NULL;
    }
};

class BinHeap
{
    BinNode *roots; 
    BinNode *min; // The node with the minimum value
    void linkTrees(BinNode*, BinNode*); // Used to link two trees. Doesn't matter if they are the
    									// same degree or not.


    BinNode* mergeRoots(BinHeap*, BinHeap*); // Used to merge two minomial heaps into one heap.
    											// the property that one binomial heap can only contain
    											// only one binomial tree of k.
    
public:
    BinHeap();
    BinHeap(BinNode*);
    bool isEmpty();
    void insert(int);
    void insert(BinNode*);
    void merge(BinHeap*);
    BinNode* first();
    BinNode* extractMin();
    void decreaseKey(BinNode*, int);
    void Delete(BinNode*);
};

BinHeap::BinHeap()
{
    this -> roots = NULL;
}

BinHeap::BinHeap(BinNode *x)
{
    this -> roots = x;
}

bool BinHeap::isEmpty()
{
    return (this -> roots == NULL);
}

void BinHeap::insert(int val){  // Takes value
	insert(new BinNode(val));
}

void BinHeap::insert(BinNode *x) // Takes a node
{
    this -> merge(new BinHeap(x));
}

// Links y to z such that y is below z which means z is the new root
void BinHeap::linkTrees(BinNode *y, BinNode *z)
{
    // Condition: y -> key >= z -> key
    y -> p = z;
    y -> f = z -> c;
    z -> c = y;
    z -> degree = z -> degree + 1;
}

// Merges the roots of two binary heaps in increasing order with respect to degrees
BinNode* BinHeap::mergeRoots(BinHeap *x, BinHeap *y)
{
    BinNode *ret = new BinNode();  // The sibling of ret will be the root of the new binomial heap
    BinNode *end = ret;
    
    BinNode *L = x -> roots;
    BinNode *R = y -> roots;
    if (L == NULL) return R;
    if (R == NULL) return L;
    while (L != NULL || R != NULL)
    {
        if (L == NULL)
        {
            end -> f = R;
            end = end -> f;
            R = R -> f;
        }
        else if (R == NULL)
        {
            end -> f = L;
            end = end -> f;
            L = L -> f;
        }
        else
        {
            if (L -> degree < R -> degree)
            {
                end -> f = L;
                end = end -> f;
                L = L -> f;
            }
            else
            {
                end -> f = R;
                end = end -> f;
                R = R -> f;
            }
        }
    }
    return (ret -> f);
}

// Merges this heap with the given heap keeping all the properties of binomial heap
void BinHeap::merge(BinHeap *bh)
{
	// H is the merged heap
    BinHeap *H = new BinHeap();
    H -> roots = mergeRoots(this, bh);
    
    if (H -> roots == NULL)
    {
        this -> roots = NULL;
        this -> min = NULL;
        return;
    }
    
    // x = root of the current binomial tree
    BinNode *prevX = NULL;
    BinNode *x = H -> roots;
    BinNode *nextX = x -> f;
    
    while (nextX != NULL)
    {
        if (x -> degree != nextX -> degree || 
        	(nextX -> f != NULL && nextX -> f -> degree == x -> degree))
        {
            prevX = x;
            x = nextX;
        }
        else if (x -> key <= nextX -> key)
        {
            x -> f = nextX -> f;
            linkTrees(nextX, x);
        }
        else
        {
            if (prevX == NULL) H -> roots = nextX;
            else prevX -> f = nextX;
            linkTrees(x, nextX);
            x = nextX;
        }
	    nextX = x -> f;
    }
    
    this -> roots = H -> roots;
    this -> min = H -> roots;
    BinNode *cur = this -> roots;
    while (cur != NULL)
    {
        if (cur -> key < this -> min -> key) this -> min = cur;
        cur = cur -> f;
    }
}

BinNode* BinHeap::first() // Returns the node with the minimum value
{
    return this -> min;
}

BinNode* BinHeap::extractMin()  //Deletes the minimum node
{
    BinNode *ret = this -> first();
    
    // delete ret from the list of roots
    BinNode *prevX = NULL;
    BinNode *x = this -> roots;
    while (x != ret)
    {
        prevX = x;
        x = x -> f;
    }
    if (prevX == NULL) this -> roots = x -> f;
    else prevX -> f = x -> f;
    
    // reverse the list of ret's children
    BinNode *revChd = NULL;
    BinNode *cur = ret -> c;
    while (cur != NULL)
    {
        //link or reverse o 
        BinNode *next = cur -> f;
        cur -> f = revChd;
        revChd = cur;
        cur = next;
    }
    
    // merge the two lists
    BinHeap *H = new BinHeap();
    H -> roots = revChd;
    this -> merge(H);
    
    return ret;
}

void BinHeap::decreaseKey(BinNode *x, int newKey)
{
    // Precondition: x -> key > newKey
    x -> key = newKey;
    BinNode *y = x;
    BinNode *z = y -> p;
    while (z != NULL && y -> key < z -> key)
    {
        // swap contents
        swap(y -> key, z -> key);
        
        y = z;
        z = y -> p;
    }
    
    if (y -> key < this -> min -> key) this -> min = y;
}

void BinHeap::Delete(BinNode *x)
{
    decreaseKey(x, -INF);
    extractMin();
}

int main()
{
    BinHeap *bh = new BinHeap();
    
    BinNode *x = new BinNode(11);
   
   int n;
   cin>>n;
   while (n--)
   {
   		int a ;
   		cin>>a;
   		bh->insert(a);
   }
    
    bh -> decreaseKey(x, 2);
    
    while (!bh -> isEmpty())
    {
        cout<<bh -> extractMin() -> key<<" ";
    }
   
    return 0;
}
