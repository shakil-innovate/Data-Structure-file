  //G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS 
  //vedio link:https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=22
  //problem link: https://bit.ly/3PvBfsm
  //{ Driver Code Starts 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
   public:
    // Function to return a list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of vertices in the graph.

        // Step 1: Calculate in-degrees of all vertices.
        vector<int> degree(n, 0); // Array to store in-degree of each vertex.

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) { // Traverse all neighbors of vertex i.
                degree[it]++; // Increment in-degree of the neighbor.
            }
        }

        // Step 2: Push all vertices with in-degree 0 into the queue.
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) // If in-degree is 0, push it into the queue.
                q.push(i);
        }

        // Step 3: Perform BFS (Kahn's Algorithm) to generate topological sort.
        vector<int> ans; // To store the topological order.
        while (!q.empty()) {
            int x = q.front(); // Get the front element from the queue.
            q.pop();
            ans.push_back(x); // Add it to the result.

            // Reduce the in-degree of its neighbors.
            for (auto it : adj[x]) {
                degree[it]--; // Decrement in-degree.
                if (degree[it] == 0) // If in-degree becomes 0, push it into the queue.
                    q.push(it);
            }
        }

        return ans; // Return the topological order.
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
        return 0; // Size mismatch indicates invalid topological order.

    vector<int> map(V, -1); // Map to store the position of each vertex in the result.
    for (int i = 0; i < V; i++) {
        map[res[i]] = i; // Store position of each vertex in res.
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) // Ensure no vertex comes before its dependencies.
                return 0;
        }
    }
    return 1; // Valid topological order.
}

int main() {
    int T;
    cin >> T; // Number of test cases.
    while (T--) {
        int N, E;
        cin >> E >> N; // Number of edges and vertices.
        int u, v;

        vector<vector<int>> adj(N); // Adjacency list representation of the graph.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Add edge from u to v.
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj); // Get topological order.

        cout << check(N, res, adj) << endl; // Validate and print the result.

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver
