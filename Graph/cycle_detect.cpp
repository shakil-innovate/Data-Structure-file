//G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS
//vedio link:https://www.youtube.com/watch?v=iTBaI90lpDQ
//problem link:https://bit.ly/3QwPVsi
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
   public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj){

     vector<int>inDegree(V,0);
        
        // Calculate in-degree for each vertex
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int>q;

        // Add all vertices with in-degree 0 to the queue
         
        for(int i=0;i<V;i++)
        {
            if(inDegree[i]==0)   q.push(i);
        }

        int cnt=0; // Count of processed nodes

        while(!q.empty())
        {
            int x=q.front();
            q.pop();
           cnt++;

            for(auto it:adj[x])
            {
                inDegree[it]--;
                if(inDegree[it]==0)   q.push(it);
            }
        }

        return (cnt!=V);  // If count of processed nodes is less than V, there is a cycle
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends