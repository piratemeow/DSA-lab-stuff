class Solution {
public:

    class DSU{
        vector<int> par, rank;

        public:
            DSU (int n)
            {
                rank = vector<int>(n+1,0);
                par = vector<int>(n+1,0);
                for (int i=1;i<=n;i++)
                {
                    par[i] = i;
                }

            }

            int find_par(int x)
            {
                if (par[x]!=x)
                {
                    par[x] = find_par(par[x]);
                }

                return par[x];
            }

            bool union_v(int p , int q)
            {
                int x = find_par(p);
                int y = find_par(q);

                if (x==y)
                {
                    return true;
                }

                if (rank[x]>rank[y])
                {
                    par[y] = x;
                }
                else if (rank[x]<rank[y])
                {
                    par[x] = y;
                }
                else
                {
                    par[y] = x;
                    rank[x]++;
                }

                return false;

            }

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DSU* dsu = new DSU(edges.size());
        

        for (int i=0;i<edges.size();i++)
        {
            if (dsu->union_v(edges[i][0],edges[i][1]))
            {
                return edges[i];
            }
        }

        return {};

        
    }
};
