  //G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS 
  //vedio link:https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=22
  //problem link: https://bit.ly/3PvBfsm
  //{ Driver Code Starts 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topologicalSort(vector<vector<int>>& adj) {
   int n = adj.size();
   vector<int> indegree(n, 0);
   
   for (int i = 0; i < n; i++)
    for (int v : adj[i])
     indegree[v]++;
     queue<int> q;

     for (int i = 0; i < n; i++)
      if (indegree[i] == 0) q.push(i);
       vector<int> topo;

       while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
         indegree[v]--;

         if (indegree[v] == 0) q.push(v);
        }
      }
    return topo;
  }
};

int main() {
 int T; cin >> T;

 while (T--) {
  int E, N; cin >> E >> N;
  vector<vector<int>> adj(N);
    
  for (int i = 0; i < E; i++) {
   int u, v; cin >> u >> v;
   adj[u].push_back(v);
  }

  Solution obj;
  
  vector<int> res = obj.topologicalSort(adj);
   for (int x : res) cout << x << " ";
     cout << "\n";
  }
}
