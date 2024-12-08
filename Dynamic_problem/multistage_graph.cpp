#include <bits/stdc++.h>
using namespace std;

void shortestPathMultistageGraph(const vector<vector<pair<int, int>>>& graph, int n);

int main() {
    int edg, vertices;
    cin >> edg >> vertices;

    vector<vector<pair<int, int>>> graph(vertices + 1); // 1-based indexing

    for (int i = 0; i < edg; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(end, weight));
    }

    shortestPathMultistageGraph(graph, vertices);

    return 0;
}

void shortestPathMultistageGraph(const vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> cost(n + 1, INT_MAX);  // Store the shortest cost to reach the sink
    vector<int> path(n + 1, -1);      // Store the path

    cost[n] = 0; // Cost to reach the sink from itself is 0

    // Calculate costs in reverse order
    for (int i = n - 1; i >= 1; i--) {
        for (const auto& edge : graph[i]) {
            int nextNode = edge.first;
            int weight = edge.second;

            // Check for valid cost to avoid overflow
            if (cost[nextNode] != INT_MAX && cost[i] > weight + cost[nextNode]) {
                cost[i] = weight + cost[nextNode];
                path[i] = nextNode;
            }
        }
    }

    // If the source cost is still INT_MAX, the sink is unreachable
    if (cost[1] == INT_MAX) {
        cout << "No valid path from source to sink.\n";
        return;
    }

    // Output the shortest path cost
    cout << "Shortest path cost: " << cost[1] << endl;

    // Output the path
    cout << "Path: ";
    int current = 1; // Start from the source
    while (current != -1) {
        cout << current << " ";
        current = path[current];
    }
    cout << endl;
}
