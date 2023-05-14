#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 524288
#define MAXC 1048576
#define NO_VALUE -1

#define LEFT(x) ( 2*(x) )
#define RIGHT(x) ( 2*(x)+1 )

int A, B, C, M;

int r() {
    A = 36969 * (A & M) + (A >> 16);
    B = 18000 * (B & M) + (B >> 16);
    return (C & ((A << 16) + B)) % 1000000;
}

int x[MAXN], y[MAXN], z[MAXN], ox[MAXN], val[MAXN];

bool cmp_x(const int &a, const int &b) {
    if (x[a] != x[b]) return x[a] < x[b];
    else if (y[a] != y[b]) return y[a] < y[b];
    else return z[a] < z[b];
}

map<int, int> st[2*MAXC];

int query(int n, int s, int e, int a, int b, int th) {
    if (s >= b || e <= a || st[n].empty()) return NO_VALUE;
    else if (s >= a && e <= b) {
        map<int, int>::iterator it = st[n].lower_bound(th);
        if (it != st[n].begin()) { it--; return it->second;}
        else return NO_VALUE;
    } else return max(query(LEFT(n), s, (s+e)/2, a, b, th), query(RIGHT(n), (s+e)/2, e, a, b, th));
}

void update(int n, int s, int e, int pos, int th, int v) {
    map<int,int>::iterator it1, it2;
    it1 = it2 = st[n].upper_bound(th);
    while (it2 != st[n].end() && it2->second <= v) it2++;
    st[n].erase(it1, it2);

    it1 = st[n].upper_bound(th);
    if (it1 == st[n].begin() || (--it1)->second < v) st[n][th] = v;

    if (e-s == 1) return;
    else if (pos < (s+e)/2) update(LEFT(n), s, (s+e)/2, pos, th, v);
    else update(RIGHT(n), (s+e)/2, e, pos, th, v);
}

int main() {
    int m, n, i, j, N, RANGE;

    while (cin >> m >> n >> A >> B && (m || n || A || B)) {
        C = ~(1<<31); M = (1<<16)-1;
        for (i=0; i<m; i++) cin >> x[i] >> y[i] >> z[i];
        for (i=m; i<m+n; i++) { x[i] = r(); y[i] = r(); z[i] = r(); }
        N = m+n;

        for (i=0; i<2*MAXC; i++) st[i].clear();

        RANGE = -1;
        for (i=0; i<N; i++) { ox[i] = i; RANGE = max(RANGE, y[i]+1); }
        sort(ox, ox+N, cmp_x);
        i = 0;
        do {
            for (j=i; j<N && x[ox[j]]==x[ox[i]]; j++){
                val[ox[j]] = max(1, query(1, 0, RANGE, 0, y[ox[j]], z[ox[j]])+1);
            }
            for (; i<j; i++) update(1, 0, RANGE, y[ox[i]], z[ox[i]], val[ox[i]]);
        } while (i < N);
        cout << query(1, 0, RANGE, 0, MAXC, MAXC) << endl;
    }

    return 0;
}