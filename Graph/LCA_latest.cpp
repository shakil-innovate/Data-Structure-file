#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG  = 17;          // log2(1e5) ≈ 17

vector<int> adj[MAXN];
int up[MAXN][LOG];            // up[v][j] = 2^j-th ancestor of v
int dep[MAXN];
int n;

void dfs(int v, int p, int d) {
    dep[v]    = d;
    up[v][0]  = p;

    for (int j = 1; j < LOG; j++)
        up[v][j] = up[up[v][j-1]][j-1];

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    // Step 1: bring u to same depth as v
    int diff = dep[u] - dep[v];
    for (int j = 0; j < LOG; j++)
        if ((diff >> j) & 1)
            u = up[u][j];

    if (u == v) return u;

    // Step 2: lift both until just below LCA
    for (int j = LOG - 1; j >= 0; j--)
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }

    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // up[root][0] = root (root is its own ancestor)
    dfs(1, 1, 0);

    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
