#include <bits/stdc++.h>
using namespace std;

struct node{
    node* links[26];
    bool flag = false;
    
};

class Trie {
public:
    node* root;

    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* n = root;

        for (int i=0;i<word.size();i++)
        {
            if (n->links[word[i]-'a']==NULL)
            {
                n->links[word[i]-'a'] = new node();
            }
            n = n->links[word[i]-'a'];
        }

        n->flag = true;
    }
    
    bool search(string word) {
        node* n = root;

        for (int i=0;i<word.size();i++)
        {
            if (n->links[word[i]-'a']==NULL)
            {
                return false;
            }

            n = n->links[word[i]-'a'];

        }

        return n->flag;
    }
    
    bool startsWith(string prefix) {
        node* n = root;

        for (int i=0;i<prefix.size();i++)
        {
            if (n->links[prefix[i]-'a']==NULL)
            {
                return false;
            }

            n = n->links[prefix[i]-'a'];

        }

        return true;
    }   
};

int main()
{
    int k;
    cin>>k;
    Trie* tr = new Trie();
    while (k--)
    {
        string s;
        cin>>s;
        tr->insert(s);
    }

    if (tr->search("Hello"))
    {
        cout<<"True\n";
    }

    else
    {
        cout<<"False\n";
    }

    if (tr->startsWith("H"))
    {
        cout<<"YES\n";
    }

    else
    {
        cout<<"NO\n";
    }


}
