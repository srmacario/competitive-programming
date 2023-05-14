#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int ans, n, a[N], b[N], f[N], sz[N], l[N], r[N];

int find(int u){
    if(f[u] == u)
        return u;
    else
        return f[u] = find(f[u]);
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    ans--;
    if(sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    l[u] = min(l[u], l[v]);
    r[u] = max(r[u], r[v]);
    f[v] = u;
}

int main(){
    scanf("%d", &n);
    ans = n;
    for(int i = 0; i < n; i++){
        f[i] = i;
        sz[i] = 1;
        l[i] = i;
        r[i] = i;
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++){
        int lb = lower_bound(b, b + n, a[i]) - b;
        int ub = upper_bound(b, b + n, a[i]) - b - 1;
        if(i < lb){
            int h = i + 1;
            while(h <= lb){
                unite(i, h);
                h = r[find(h)] + 1;
            }
        }
        else if(i > ub){
            int h = i - 1;
            while(h >= ub){
                unite(i, h);
                h = l[find(h)] - 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}