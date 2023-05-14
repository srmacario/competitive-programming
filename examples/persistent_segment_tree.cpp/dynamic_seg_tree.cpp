#include <bits/stdc++.h>

/* tested:
*/

vector<int> e, d, sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

int update(int pos, int ini, int fim, int id, int val){
    int novo = create();
    
    sum[novo] = sum[pos];
    e[novo] = e[pos];
    d[novo] = d[pos];

    if(ini == fim){
        sum[pos] = val;
        return novo;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        int aux = update(e[pos], ini, m, id, val);
        e[pos] = aux;
    }
    else{
        int aux = update(d[pos], m + 1, fim, id, val);
        d[pos] = aux;
    }

    sum[pos] = sum[e[pos]] + sum[d[pos]];
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return INT_MAX;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return sum[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}