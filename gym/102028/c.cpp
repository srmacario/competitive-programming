#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 3e5 + 5;

int n, id[2][N], pos[2][N];
int lz[2][4*N][2], st[2][4*N], v[2][N], lz_op[2];
set<int> all, tog[2][2];

void build(int s, int p, int l, int r){
    if(l == r) {st[s][p] = v[s][l]; return;}
    build(s, 2*p, l, (l + r)/2);
    build(s, 2*p+1, (l+r)/2 + 1, r);
}

void push(int s, int p, int l, int r){
    // set
    if(lz[s][p][1]){
        st[s][p] = lz[s][p][1];
        if(l != r){
            if (lz[s][2*p][1]) {
                lz[s][2*p][1] = lz[s][p][1];
            } else {
                lz[s][2*p][0] = 0;
                lz[s][2*p][1] = lz[s][p][1];
            }

            if (lz[s][2*p+1][1]) {
                lz[s][2*p+1][1] = lz[s][p][1];
            } else {
                lz[s][2*p+1][0] = 0;
                lz[s][2*p+1][1] = lz[s][p][1];
            }
        }
        lz[s][p][1] = 0;
    }

    // sum
    if(lz[s][p][0]){
        st[s][p] += lz[s][p][0];
        if(l != r){
            if (lz[s][2*p][1]) {
                lz[s][2*p][1] += lz[s][p][0];
            } else {
                lz[s][2*p][0] += lz[s][p][0];
            }

            if (lz[s][2*p+1][1]) {
                lz[s][2*p+1][1] += lz[s][p][0];
            } else {
                lz[s][2*p+1][0] += lz[s][p][0];
            }
        }
        lz[s][p][0] = 0;
    }
}

void sum(int i, int j, int v, int s, int p = 1, int l = 1, int r = n){
    push(s, p, l, r);
    if(l > j or r < i) return;
    if(l >= i and j >= r){
        lz[s][p][0] += v;
        push(s, p, l, r);
        return;
    }
    sum(i, j, v, s, 2*p, l, (l + r)/2);
    sum(i, j, v, s, 2*p + 1, (l + r)/2 + 1, r);
    st[s][p] = max(st[s][2*p], st[s][2*p + 1]);
}

void set_val(int i, int j, int v, int s, int p = 1, int l = 1, int r = n){
    push(s, p, l, r);
    if(l > j or r < i) return;
    if(l >= i and j >= r){
        lz[s][p][1] = v;
        push(s, p, l, r);
        return;
    }
    set_val(i, j, v, s, 2*p, l, (l + r)/2);
    set_val(i, j, v, s, 2*p + 1, (l + r)/2 + 1, r);
    st[s][p] = max(st[s][2*p], st[s][2*p + 1]);
}

int query(int i, int j, int s, int p = 1, int l = 1, int r = n){
    push(s, p, l, r);
    if(l > j or r < i) return 0;
    if(l >= i and j >= r) return st[2][p];
    return max(query(i, j, s, 2*p, l, (l + r)/2), query(i, j, s, 2*p + 1, (l + r)/2 + 1, r));
}

int ub(int v, int s, int p = 1, int l = 1, int r = n + 1){
    push(s, p, l, r);
    if(l == r){
        return l;
    }
    if(st[s][2*p] <= v) return ub(v, 2*p + 1, (l + r)/2 + 1, r);
    return ub(v, 2*p,  l, (l + r)/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> pos[0][i] >> pos[1][i];
            id[0][pos[0][i]] = i;
            id[1][pos[1][i]] = i;
        }
        //create segs
        for(int k = 0; k < 2; k++){
            for(int i = 1; i <= n + 1; i++)
                v[k][i] = i;
            build(k, 1, 1, n + 1);
        }
        //querys
        for(int i = 1; i <= m; i++){
            char op;
            cin >> op;
            if(op == '!'){
                cout << all.size() << "\n";
            }
            else if(op == '?'){
                int k;
                cin >> k;
                cout << query(pos[0][i], pos[0][i], 0) << " " << query(pos[1][i], pos[1][i], 1) << "\n";
            }
            else{
                int k;
                cin >> k;
                if(op == 'L'){
                    int lft = ub(1, 1), rgt = ub(k + 1, 1);
                    set_val(1, rgt - 1, 1, 1);
                    sum(rgt, n, -k, 1);
                    for(int i = lft; i < rgt; i++){
                        if(tog[0][0].count(i)){
                            tog[0][0].erase(i);
                            all.insert(i);
                        } else if(tog[0][1].count(i)){
                            tog[0][1].erase(i);
                            all.insert(i);
                        }
                        else{
                            tog[1][0].insert(i);
                        }
                    }
                }
                if(op == 'R'){
                    int rgt = ub(n, 1), lft = ub(n - k - 1, 1);
                    set_val(lft, n, 1, 1);
                    sum(1, lft - 1, k, 1);
                    for(int i = lft; i < rgt; i++){
                        if(tog[0][0].count(i)){
                            tog[0][0].erase(i);
                            all.insert(i);
                        } else if(tog[0][1].count(i)){
                            tog[0][1].erase(i);
                            all.insert(i);
                        }
                        else{
                            tog[1][1].insert(i);
                        }
                    }
                    
                }
                if(op == 'D'){
                    int lft = ub(1, 0), rgt = ub(k + 1, 0);
                    set_val(1, rgt - 1, 1, 0);
                    sum(rgt, n, -k, 0);
                    for(int i = lft; i < rgt; i++){
                        if(tog[1][0].count(i)){
                            tog[1][0].erase(i);
                            all.insert(i);
                        } else if(tog[1][1].count(i)){
                            tog[1][1].erase(i);
                            all.insert(i);
                        }
                        else{
                            tog[0][0].insert(i);
                        }
                    }
                }
                if(op == 'U'){
                    int rgt = ub(n, 0), lft = ub(n - k - 1, 0);
                    set_val(lft, n, 1, 0);
                    sum(1, lft - 1, k, 0);
                    for(int i = lft; i < rgt; i++){
                        if(tog[1][0].count(i)){
                            tog[1][0].erase(i);
                            all.insert(i);
                        } else if(tog[1][1].count(i)){
                            tog[1][1].erase(i);
                            all.insert(i);
                        }
                        else{
                            tog[0][1].insert(i);
                        }
                    }
                }
            }
        }
    }
    return 0;
}