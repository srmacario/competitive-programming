int par[N], sz[N];

int find (int a) {
    while(a != par[a]){
        a = par[a];
    }
    return a;
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
}