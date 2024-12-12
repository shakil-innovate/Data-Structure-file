//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    void dfs_(vector<int>&vis,vector<vector<int>>&adj,int i,stack<int>&st)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs_(vis,adj,it,st);
            }
        }
        st.push(i);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
     int n=adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs_(vis,adj,i,st);
            }
        }
        vector<int>ans;
        
        while(!st.empty())
        {
            int x=st.top();
            ans.push_back(x);
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends