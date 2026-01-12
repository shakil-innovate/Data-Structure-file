#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e5+5;

vector<ll> arr(MAXN), tree(4*MAXN, LLONG_MAX);

// Build segment tree for RMQ
void build(ll low, ll high, ll index) {
    if(low == high) {
        tree[index] = arr[low];
    } else {
        ll mid = (low + high)/2;
        build(low, mid, 2*index + 1);
        build(mid+1, high, 2*index + 2);
        tree[index] = min(tree[2*index + 1], tree[2*index + 2]);
    }
}

// Update a position
void update(ll low, ll high, ll index, ll pos, ll value) {
    if(low == high) {
        tree[index] = value;
    } else {
        ll mid = (low + high)/2;
        if(pos <= mid)
            update(low, mid, 2*index + 1, pos, value);
        else
            update(mid+1, high, 2*index + 2, pos, value);
        tree[index] = min(tree[2*index + 1], tree[2*index + 2]);
    }
}

// Query min in range [qlow, qhigh]
ll query(ll qlow, ll qhigh, ll low, ll high, ll index) {
    if(qlow > high || qhigh < low) return LLONG_MAX; // completely outside
    if(qlow <= low && high <= qhigh) return tree[index]; // completely inside
    ll mid = (low + high)/2;
    return min(query(qlow, qhigh, low, mid, 2*index + 1),
               query(qlow, qhigh, mid+1, high, 2*index + 2));
}

int main() {
    ll n, m;
    cin >> n >> m;
    for(ll i=0;i<n;i++) cin >> arr[i];

    build(0, n-1, 0);

    while(m--) {
        ll type, l, r;
        cin >> type >> l >> r;
        if(type == 1) update(0, n-1, 0, l, r); // update a[l] = r
        else if(type == 2) cout << query(l, r-1, 0, n-1, 0) << "\n"; // RMQ
    }
}
