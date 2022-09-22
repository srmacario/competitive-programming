#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, p[10];
vector<string> s;
string t[N];
set<string> all_ts;

pair<bool, string> calc(string cur, int pos, int diff){
    if(pos == n){
        if(!all_ts.count(cur)){
            return {true, cur};
        }
        return {false, ""};
    }
    pair<bool, string> ans;
    for(int i = 0; i <= diff; i++){
        string tmp = cur;
        for(int j = 0; j <= i; j++) tmp += "_";
        tmp += s[pos];
        ans = calc(tmp, pos + 1, diff - i);
        if(ans.st) return ans;
    }
    return {false, ""};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int all_size = 0;
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        all_size += s[i].size();
    }
    sort(s.begin(), s.end());
    int min_size = all_size + n - 1;
    int diff = 16 - min_size;
    if((min_size < 3 and n == 1)){
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];
        all_ts.insert(t[i]);
    }
    do{
        pair<bool, string> ans = calc(s[0], 1, diff);
        if(ans.st){
            cout << ans.nd << "\n";
            return 0;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << "-1\n";
    return 0;
}