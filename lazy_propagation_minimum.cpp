#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

const int MAXN = 1000; // Maximum size of the array
int arr[MAXN], tree[4 * MAXN], lazy[4 * MAXN]; // Segment tree and lazy propagation array
int n, m;

void build(int low, int high, int index) {
    if (low == high) {
        tree[index] = arr[low];  // Store actual array values in the segment tree
        return;
    }
    int mid = (low + high) >> 1; // Calculate middle index
    build(low, mid, 2 * index + 1); // Recursively build left subtree
    build(mid + 1, high, 2 * index + 2); // Recursively build right subtree

    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]); // Merge results
}

void propagate(int low, int high, int pos) {
    if (lazy[pos] != 0) { // If there is a pending update
        tree[pos] += lazy[pos]; // Apply the lazy update

        if (low != high) {  // If not a leaf node, propagate to children
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0; // Clear lazy value after propagation
    }
}

void updateLazy(int startRange, int endRange, int delta, int low, int high, int pos) {
    propagate(low, high, pos); // Apply pending updates

    if (startRange > high || endRange < low) {
        return; // Out of range, no update required
    }

    if (startRange <= low && endRange >= high) { // Total overlap
        tree[pos] += delta; // Apply update
        if (low != high) { // If not a leaf, mark children for lazy propagation
            lazy[2 * pos + 1] += delta;
            lazy[2 * pos + 2] += delta;
        }
        return;
    }

    int mid = (low + high) >> 1;
    updateLazy(startRange, endRange, delta, low, mid, 2 * pos + 1); // Update left child
    updateLazy(startRange, endRange, delta, mid + 1, high, 2 * pos + 2); // Update right child

    tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]); // Recalculate minimum
}

int queryMin(int qlow, int qhigh, int low, int high, int pos) {
    propagate(low, high, pos); // Apply pending lazy updates

    if (qlow > high || qhigh < low) {
        return INT_MAX; // No overlap, return maximum possible value
    }

    if (qlow <= low && qhigh >= high) {
        return tree[pos]; // Total overlap, return stored value
    }

    int mid = (low + high) >> 1;
    return min(queryMin(qlow, qhigh, low, mid, 2 * pos + 1), // Query left child
               queryMin(qlow, qhigh, mid + 1, high, 2 * pos + 2)); // Query right child
}

int main() {
    cin >> n >> m; // Read number of elements and number of queries

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read array elements
    }

    memset(tree, 0, sizeof(tree)); // Initialize segment tree to zero
    memset(lazy, 0, sizeof(lazy)); // Initialize lazy array to zero

    build(0, n - 1, 0); // Build the segment tree

    while (m--) {
        string command;
        cin >> command;

        if (command == "update") {
            int x, y, z;
            cin >> x >> y >> z;
            updateLazy(x, y, z, 0, n - 1, 0); // Perform range update
        }

        if (command == "min") {
            int x, y;
            cin >> x >> y;
            cout << queryMin(x, y, 0, n - 1, 0) << endl; // Perform range minimum query
        }
    }
}
