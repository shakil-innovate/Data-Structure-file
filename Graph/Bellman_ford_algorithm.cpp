//problem:4.4 Bellman Ford Algorithm - Single Source Shortest Path - Dynamic Programming
//vedio link:https://www.youtube.com/watch?v=FtN3BYH2Zes
//problem link: https://bit.ly/3K7emug

//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  
     *   Function to implement Bellman-Ford algorithm
     *   edges: vector of vectors which represents the graph (each vector contains [u, v, w])
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Initialize the distance vector with a large value (1e8) to signify infinity
        vector<int> dist(V, 1e8);
        dist[src] = 0; // Distance to the source vertex is 0

        // Relax all edges V-1 times (standard Bellman-Ford algorithm step)
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0]; // Start vertex of the edge
                int v = it[1]; // End vertex of the edge
                int w = it[2]; // Weight of the edge
                
                // Relax the edge if a shorter path is found
                if (dist[u] != 1e8 && (dist[u] + w) < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycles in the graph
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            // If a shorter path is still found, a negative weight cycle exists
            if (dist[u] != 1e8 && (dist[u] + w) < dist[v]) {
                return {-1}; // Return -1 to indicate the presence of a negative weight cycle
            }
        }

        // Return the final distance vector
        return dist;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore newline after the test case count
    while (t--) {
        int N, m;
        cin >> N >> m; // Number of vertices (N) and edges (m)

        vector<vector<int>> edges; // Graph representation

        // Input edges of the graph
        for (int i = 0; i < m; ++i) {
            int u, v, w; // Start vertex (u), end vertex (v), and weight (w)
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src; // Source vertex
        cin >> src;
        cin.ignore(); // Ignore newline after source input

        Solution obj; // Create an instance of the Solution class
        vector<int> res = obj.bellmanFord(N, edges, src); // Call Bellman-Ford function

        // Output the result
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
