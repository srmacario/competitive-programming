#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, TP, FP, FN, TN, l[2], r[2];
vector<pair<int, int>> scs;
/*
    l[0] == TN
    l[1] == FN

    r[1] == TP 
    r[0] == FP
*/

pii tpr(){
    return {r[1], l[1] + r[1]};
}

pii fpr(){
    return {r[0], l[0] + r[0]};
}

pii max_tpr(pii cur_tpr, pii old_tpr){
    if(1ll * cur_tpr.st * old_tpr.nd >= 1ll * cur_tpr.nd * old_tpr.st) return cur_tpr;
    return old_tpr;
}

ld calc_num(pii t){
    return ((ld)(t.st) / (ld)(t.nd));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin >> c >> s;
        scs.push_back({-s, c == '+'});
        r[c == '+']++;
    }
    sort(scs.begin(), scs.end());
    map<pii, pii> grid;
    grid[fpr()] = tpr();
    for(int i = (int)scs.size() - 1; i >= 0; i--){
        l[scs[i].nd]++, r[scs[i].nd]--;
        if(!grid.count(fpr())) grid[fpr()] = tpr();
        else{
            grid[fpr()] = max_tpr(tpr(), grid[fpr()]);
        }
    }
    ld ans = 0;
    int cnt = 0;
    pair<pii, pii> last_g;
    for(auto g : grid){
        if(cnt){
            ans += (calc_num(g.st) - calc_num(last_g.st)) * (calc_num(last_g.nd));
        }
        last_g = g;
        cnt++;
    }
    cout << setprecision(15) << fixed << ans << "\n";
    return 0;
}