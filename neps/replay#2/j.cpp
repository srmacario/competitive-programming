#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int m, c;
map <int, int> mom_col, mom_row, chc_col, chc_row;
map <pii, int> is_chc;
set <int> col, row, buf_col, buf_row;
pii mom[N], chc[N];

int main(){
    scanf("%d%d", &m, &c);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &mom[i].st, &mom[i].nd);
        mom_col[mom[i].st]++;
        mom_row[mom[i].nd]++;
        if(mom_col[mom[i].st] == 1){
            col.insert(mom[i].st);
        }
        if(mom_row[mom[i].nd] == 1){
            row.insert(mom[i].nd);
        }
        if(mom_col[mom[i].st] == 2){
            col.erase(mom[i].st);
            buf_col.insert(mom[i].st);
        }
        if(mom_row[mom[i].nd] == 2){
            row.erase(mom[i].nd);
            buf_row.insert(mom[i].nd);
        }
    }
    for(int i = 0; i < c; i++){
        scanf("%d %d", &chc[i].st, &chc[i].nd);
        if(!buf_row.count(chc[i].nd) and !buf_col.count(chc[i].st)){
            is_chc[chc[i]]++;
            chc_col[chc[i].st]++;
            chc_row[chc[i].nd]++;
        }
    }
    piii ans = {0, {0, 0}};
    for(auto i : col){
        for(auto j : row){
            int qtd = chc_col[i] + chc_row[j] - is_chc[{i, j}];
            piii tmp = {qtd, {i, j}};
            ans = max({ans, tmp});
        }
    }
    for(auto i : col){
        int qtd = chc_col[i];
        piii tmp = {qtd, {i, 0}};
        ans = max({ans, tmp});
    }
    for(auto j : row){
        int qtd = chc_row[j];
        piii tmp = {qtd, {0, j}};
        ans = max({ans, tmp});
    }
    cout << ans.nd.st << " " << ans.nd.nd << "\n" << ans.st << "\n";
    return 0;
}