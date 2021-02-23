int stm[4*N], lazym[4*N], v[4*N];

void buildm (int p, int l, int r) {
    if (l == r) {stm[p] = v[l]; return;}
    buildm (2*p, l, (l+r)/2);
    buildm (2*p+1, (l+r)/2+1, r);
    stm[p] = min(stm[2*p], stm[2*p+1]);
}

void pushm (int p, int l, int r) {
    if (lazym[p]) {
        stm[p] = lazym[p];
        if (l != r) {
            lazym[2*p] = lazym[p];
            lazym[2*p+1] = lazym[p];
        }
        lazym[p] = 0;
    }
}

int querym (int p, int l, int r, int i, int j) {
    pushm(p, l, r);
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return stm[p];
    int x = querym(2*p, l, (l+r)/2, i, j);
    int y = querym(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void updatem (int p, int l, int r, int i, int j, int k) {
    pushm(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazym[p] = k;
        pushm(p, l, r);
        return;
    }
    updatem(2*p, l, (l+r)/2, i, j, k);
    updatem(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) stm[p] = min(stm[2*p], stm[2*p+1]);
}