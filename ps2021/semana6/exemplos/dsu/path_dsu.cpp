int par[N];

int find (int a) {
    while(a != par[a]){
        a = par[a];
    }
    return a;
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}