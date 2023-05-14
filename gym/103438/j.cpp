#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

// BC = (b + c - a) / 2
int n, BC, cnt[3];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < 2*n; i++) cnt[s[i] - 'A']++;
    BC = (cnt[1] + cnt[2] - cnt[0]) / 2;
    if(BC < 0){
        cout << "NO\n";
        return 0;
    }
    vector<int> pos;
    int cur = 0;
    vector<pii> ans;
    set<int> used;
    //get BC positions
    for(int i = 0; (i < 2 * n) and BC; i++){
        if(s[i] == 'B') pos.push_back(i);
        if(cur < pos.size() and s[i] == 'C'){
            ans.push_back({pos[cur], i});
            used.insert(i), used.insert(pos[cur]);
            cur++;
            BC--;
        }
    }
    if(BC){
        cout << "NO\n";
        return 0;
    }
    //get AC/ABpositions
    pos.clear();
    for(int i = 0; (i < 2 * n); i++){
        if(s[i] == 'A') pos.push_back(i);
        if(pos.size() and s[i] != 'A' and !used.count(i)){
            ans.push_back({pos.back(), i});
            used.insert(i), used.insert(pos.back());
            pos.pop_back();
        }
    }
    if(used.size() != 2 * n){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto p : ans) cout << p.st + 1 << " " << p.nd + 1 << "\n";
    return 0;
}