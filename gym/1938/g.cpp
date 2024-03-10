#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> s(n);
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<vector<int>> cnt(n, vector<int> (n, 0));
        vector<vector<unordered_map<int, int>>> v(m, vector<unordered_map<int, int>>(26));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i][j] != '.')
                    v[j][s[i][j] - 'A'][i]++;
            }
        }
        vector<bool> off(n, false);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < 26; j++) {
                unordered_map<int, int> remove;
                for(auto [e, __] : v[i][j]) {
                    for(auto [f, k_] : v[i][j]) {
                        if(e >= f) continue;
                        cnt[e][f]++;
                        if(cnt[e][f] == k && !off[f]) {
                            remove[f]++;
                            off[f] = true;
                        }
                    }
                }
                while(!remove.empty()) {
                    unordered_map<int, int> rm;
                    for(auto [rem, ashlkdfasjf] : remove) {
                        for(int pos = i + 1; pos < m; pos++) {
                            if(s[rem][pos] == '.') continue;
                            int pp = s[rem][pos] - 'A';
                            v[pos][pp].erase(rem);
                        }
                    }
                    for(auto [rem, gsadga] : remove) {
                        for(int pos = i + 1; pos < m; pos++) {
                            if(s[rem][pos] == '.') continue;
                            int pp = s[rem][pos] - 'A';
                            for(auto [e, asfkjlaksdjf] : v[pos][pp]) {
                                cnt[min(rem, e)][max(e, rem)]++;
                                if(cnt[min(rem, e)][max(rem, e)] == k && !off[max(rem, e)]) {
                                    rm[max(rem, e)]++;
                                    off[max(rem, e)] = true;
                                }
                            }
                        }
                    }
                    remove = rm;
                }
            }
        }
        pair<int, int> bst = {n + 1, n + 1};
        for(int j = n - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(cnt[i][j] >= k) {
                    bst = {i + 1, j + 1};
                }
        }
            }
        if(bst.first != n + 1) {
            cout << bst.first << " " << bst.second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}