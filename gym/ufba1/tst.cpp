int stm[4*N];

int querym (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return stm[p];
    int x = querym(2*p, l, (l+r)/2, i, j);
    int y = querym(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void updatem (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {stm[p] = v; return;}
    updatem (2*p, l, (l+r)/2, x, v);
    updatem (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) stm[p] = max(stm[2*p], stm[2*p+1]);
}