#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int e, t[N], m[N], nxt[N], q[N], x, in[N], out[N];
pair<pii, int> r[N];
ll ans[N], bt[N];
vector<int> adj[N];

void ins(ll val, int p){
    while(p < N){
        bt[p] += val;
        p += p & -p;
    }
}

ll qq(int p){
    ll rr = 0;
    while(p){
        rr += bt[p];
        p -= p & -p;
    }
    return rr;
}

ll query(int a, int b){
    return qq(b) - qq(a);
}

void dfs(int i){
    x++;
    in[i] = x;
    ins(t[i], x);
    for(int j : adj[i]){
        r[j - 1].st.nd = r[i - 1].st.nd + 1;
        dfs(j);
    }
    out[i] = x;
}

int main(){
    scanf("%d", &e);
    for(int i = 1; i <= e; i++){
        scanf("%d %d %d", &m[i], &r[i - 1].st.st, &t[i]);
        r[i - 1].nd = i;
        if(m[i] > 0)
            adj[m[i]].push_back(i);
    }
    for(int i = 1; i <= e; i++)
        if(m[i] == -1)
            dfs(i);
    sort(r, r + e);
    for(int i = 0; i < e; i++){
        int id = r[e - i - 1].nd;
        ans[id] = query(in[id], out[id]);
        ins(-t[id], in[id]);
    }
    for(int i = 1; i <= e; i++)
        printf("%lld\n", ans[i]);
    return 0;
}