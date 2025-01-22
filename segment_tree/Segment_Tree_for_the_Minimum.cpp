//B. Segment Tree for the Minimum
//problem link:https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Arrays to store the input array and segment tree
vector<ll> arr(100000), tree(1000000);

// Function to build the segment tree
void build(ll low, ll high, ll index) {
    if (low == high)
        tree[index] = arr[low]; // If it's a leaf node, store the corresponding array value
    else {
        ll mid = (low + high) >> 1; // Calculate the mid-point
        build(low, mid, index * 2 + 1); // Recursively build the left subtree
        build(mid + 1, high, index * 2 + 2); // Recursively build the right subtree
        tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2]; // Store the sum of the left and right children
    }
}

// Function to update a value in the segment tree
void update(ll low, ll high, ll index, ll pos, ll value) {
    if (low == high) {
        tree[index] = value; // Update the value at the leaf node
    } else {
        ll mid = (low + high) / 2; // Calculate the mid-point
        if (pos <= mid) {
            update(low, mid, 2 * index + 1, pos, value); // Update the left subtree
        } else {
            update(mid + 1, high, 2 * index + 2, pos, value); // Update the right subtree
        }
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2]; // Update the current node's value
    }
}

// Function to query the sum of a range in the segment tree
ll sum(ll qlow, ll qhigh, ll low, ll high, ll index) {
    if (qlow <= low && qhigh >= high)
        return tree[index]; // If the current range is completely within the query range, return the node's value

    if (qlow > high || qhigh < low)
        return 0; // If the current range is completely outside the query range, return 0

    ll mid = (low + high) >> 1; // Calculate the mid-point
    return sum(qlow, qhigh, low, mid, index * 2 + 1) + sum(qlow, qhigh, mid + 1, high, index * 2 + 2); // Query the left and right subtrees and return their sum
}

int main() {
    ll n, m;
    cin >> n >> m; // Input the size of the array and number of queries

    for (ll i = 0; i < n; i++) cin >> arr[i]; // Input the array elements

    build(0, n - 1, 0); // Build the segment tree

    // Processing the queries
    for (ll i = 0; i < m; i++) {
        ll a, l, r;
        cin >> a >> l >> r; // Input the query type and range

        if (a == 1) {
            update(0, n - 1, 0, l, r); // Update operation
        } else if (a == 2) {
            cout << sum(l, r - 1, 0, n - 1, 0) << endl; // Sum query operation
        }
    }
}
