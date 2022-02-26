int par[N], sz[N], rank[N];

int find (int a) {
    return par[a] == a ? a : par[a] = find(par[a]));
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if(rank[a] > rank[b]){
        par[b] = a;
    }
    else{
        if(rank[a] == rank[b]) rank[a]++;
        par[a] = b;
    }
    par[b] = a;
}