int par[N]

int find (int a) {
    return par[a];
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    for(int i = 1; i <= n; i++){
        if(par[i] == a) par[i] = b;
    }
}