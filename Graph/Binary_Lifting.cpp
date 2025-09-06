problem link:https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
class TreeAncestor {
public:
    vector<vector<int>>up;
    vector<int>depth;
    int LOG=0;
    TreeAncestor(int n, vector<int>& parent) {
        while((1<<LOG)<=n)LOG++;

        up.resize(n,vector<int>(LOG,-1));
        depth.resize(n,0);

        vector<vector<int>>g(n);

        //child setup
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                g[parent[i]].push_back(i);
            }
        }

            stack<int>st;
            st.push(0);
            

          //find depth
            while(!st.empty())
            {
                int node=st.top();
                st.pop();

                for(auto child:g[node])
                {
                    st.push(child);
                    depth[child]=depth[node]+1;
                }
            }

     //build binary lifting   
   for(int i=1;i<n;i++)up[i][0]=parent[i];

     for(int j=1;j<LOG;j++)
     {
        for(int v=0;v<n;v++)
        {
            int mid=up[v][j-1];
            up[v][j]=(mid==-1?-1:up[mid][j-1]);
        }
     }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k)return -1;

        for(int j=0;j<LOG;j++)
        {
            if(k&(1<<j))node=up[node][j];
            if( node==-1)return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
