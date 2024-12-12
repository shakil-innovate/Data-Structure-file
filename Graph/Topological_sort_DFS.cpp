//G-21. Topological Sort Algorithm | DFS
//vedio link:https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=21
//problem link: https://bit.ly/3PvBfsm
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    // Helper function for DFS traversal to perform topological sorting.
    // It marks the current node as visited and recursively visits all its neighbors.
    // After visiting all neighbors, it pushes the current node onto the stack.
    void dfs_(vector<int>& vis, vector<vector<int>>& adj, int i, stack<int>& st) {
        vis[i] = 1; // Mark the current node as visited
        for (auto it : adj[i]) { // Iterate over all neighbors of the current node
            if (!vis[it]) { // If the neighbor is not visited, perform DFS on it
                dfs_(vis, adj, it, st);
            }
        }
        st.push(i); // Push the current node onto the stack after visiting all its neighbors
    }
  public:
    // Function to return a list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of vertices in the graph
        vector<int> vis(n, 0); // Visited array to keep track of visited nodes
        stack<int> st; // Stack to store the topological order

        // Perform DFS for every unvisited node
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs_(vis, adj, i, st);
            }
        }

        vector<int> ans; // Vector to store the final topological order

        // Pop all elements from the stack to get the topological order
        while (!st.empty()) {
            int x = st.top();
            ans.push_back(x);
            st.pop();
        }

        return ans; // Return the topological order
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
        return 0; // If the result does not contain all vertices, it is invalid

    vector<int> map(V, -1); // Map to store the position of each vertex in the result
    for (int i = 0; i < V; i++) {
        map[res[i]] = i; // Map the vertex to its position in the result
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            // If a vertex appears before one of its dependencies, return invalid
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1; // If all dependencies are satisfied, return valid
}

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N, E;
        cin >> E >> N; // Read the number of edges and vertices
        int u, v;

        vector<vector<int>> adj(N); // Adjacency list representation of the graph

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v; // Read the edge from u to v
            adj[u].push_back(v); // Add v to the adjacency list of u
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj); // Get the topological order

        cout << check(N, res, adj) << endl; // Check if the order is valid and print the result

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
