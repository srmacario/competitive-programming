// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round #20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Date / Time: 
// Author: cosenza
// всё что ни делается - всё к лучшему
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define LINF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int N = 1e5+5;

priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, std::greater<pair<ll, ll>>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> dist[n + 1];
    vector<ll> cost(n + 1, LINF);
    vector<ll> path(n + 1, -1);
    vector<bool> mark(n + 1, false);
    if(m == 1) {
        int x, y, w;
        cin >> x >> y >> w;
        if(x != 1 or y != n) {
            cout << -1 << "\n";
        } else {
            cout << x << " " << y << "\n";
        }
        exit(0);
    }
    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x].push_back(make_pair(y, w));
        dist[y].push_back(make_pair(x, w));
    }
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        ll c = p.first, a = p.second;
        if(cost[a] < c or mark[a]) {
            continue;
        }
        mark[a] = true;
        for(auto k : dist[a]) {
            int b = k.first, d = k.second;
            if(cost[b] > d + c) {
                path[b] = a;
                cost[b] = d + c;
                q.push(make_pair(c + d, b));
            }
        }
    }
    if(path[n] == -1) {
        cout << -1 << "\n";
        return 0;
    }
    stack<int> pp;
    int v = n;
    while(v != 1) {
        pp.push(v);
        v = path[v];
    }
    pp.push(1);
    while(!pp.empty()) {
        cout << pp.top() << " ";
        pp.pop();
    }
    return 0;
}