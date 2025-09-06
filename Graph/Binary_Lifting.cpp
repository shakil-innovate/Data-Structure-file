problem link:https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
class TreeAncestor {
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);

        // build tree children
        vector<vector<int>> g(n);
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) root = i;
            else g[parent[i]].push_back(i);
        }

        // DFS using stack to compute depth and up[v][0]
        stack<int> st;
        st.push(root);
        depth[root] = 0;
        up[root][0] = -1;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            for (int child : g[node]) {
                depth[child] = depth[node] + 1;
                up[child][0] = node;
                st.push(child);
            }
        }

        // build binary lifting table safely
        for (int j = 1; j < LOG; j++) {
            for (int v = 0; v < n; v++) {
                int mid = up[v][j-1];
                up[v][j] = (mid == -1 ? -1 : up[mid][j-1]);
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};
