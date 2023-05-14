#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    ll ans = 1, n = (int)s.size();
    map<char, vector<ll>> ch;
    for(int i = 0; i < n; i++) ch[s[i]].push_back(i);
    ll pos = ch[t[0]][0];
    for(int i = 1; i < (int)t.size(); i++){
        if(ch[t[i]].end() == upper_bound(ch[t[i]].begin(), ch[t[i]].end(), pos)){
            pos = ch[t[i]][0];
            ans++;
        }
        else pos = *upper_bound(ch[t[i]].begin(), ch[t[i]].end(), pos);
    }
    cout << ans << "\n";
    return 0;
}
/*
    abcd -> abcdabcdabcd
    dcba

*/