#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    vector<int> sa, lcp_v;
    vector<vector<int>> cs;
    int n;

    int add(int a, int b) { return a + b >= n ? a + b - n : a + b; }
    int sub(int a, int b) { return a - b < 0 ? a - b + n : a - b; }

    SuffixArray(vector<int>& s, bool store_steps = false, bool build_lcp = true) {
        s.push_back(-1);
        n = (int)s.size();
        sa = sort_shifts(s, store_steps);
        if (build_lcp) {
            lcp_v = build_lcp_v(s);
            lcp_v.erase(lcp_v.begin());
        }
        sa.erase(sa.begin());
        s.pop_back();
    }

    vector<int> sort_shifts(vector<int>& s, bool store_steps) {

    }
}

// M -> n log n + q log n
const int M = 1e7 + 5;
const int N = 2e5 + 5;

int st[M], lc[M], rc[M];
int cnt;
int n, v[N];

void clear() {
    cnt = 0;
    roots.clear();
}

vector<int> roots;

void init(int p = 0, int l = 1, int r = n) {
    if (l == r) {
        st[p] = v[l];
        return;
    }

    int mid = (l + r) / 2;

    lc[p] = find(lc[p]);
    rc[p] = find(rc[p]);

    init(lc[p], l, mid);
    init(rc[p], mid + 1, r);

    st[p] = st[lc[p]] + st[rc[p]];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

}