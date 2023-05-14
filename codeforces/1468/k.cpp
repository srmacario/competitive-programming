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

pii walk(pii pos, char c){
    if(c == 'U') pos.nd++;
    if(c == 'D') pos.nd--;
    if(c == 'R') pos.st++;
    if(c == 'L') pos.st--;
    return pos;
}

vector<pii> build(string s){
    pii pos = {0,0};
    vector<pii> ans;
    ans.pb(pos);
    for(int i=0;i<s.size();i++){
        pos = walk(pos,s[i]);
        ans.pb(pos);
    }
    return ans;
}

bool query(string s, pii f){
    pii pos = {0,0};
    for(int i=0;i<s.size();i++){
        pii nxt = walk(pos,s[i]);
        if(nxt == f) continue;
        pos = nxt;
    }
    if(pos.st == 0 and pos.nd == 0) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<pii> w = build(s);
        pii ans = {0,0};
        for(int i=0;i<w.size();i++){
            if(query(s,w[i])) ans = w[i];
        }
        cout << ans.st << " " << ans.nd << "\n";
    }
    return 0;
}