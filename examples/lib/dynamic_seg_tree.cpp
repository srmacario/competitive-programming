#include <bits/stdc++.h>

vector<int> e, d, min;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    min.push.back(0);
    e.push_back(0);
    d.push_back(0);
    return min.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        min[pos] = val;
        return;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        if(e[pos] == 0) e[pos] = create();
        update(e[pos], ini, m, id, val);
    }
    else{
        if(d[pos] == 0) d[pos] = create();
        update(d[pos], m + 1, fim, id, val);
    }

    min[pos] = min(min[e[pos]], min[d[pos]]);
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return INT_MAX;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return min[pos];
    
    int m = (ini + fim) >> 1;
    return min(query(e[pos], ini, m, p, q), query(d[pos], m + 1, fim, p, q));
}