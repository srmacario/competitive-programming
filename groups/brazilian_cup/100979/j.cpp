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

int n, ans[3];
string p, x;
set<string> c[2];

string mn(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i] <= 'Z' and s[i] >= 'A') s[i] = s[i] - 'A' + 'a';
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p;
    p = mn(p);
    for(int i=0;i<=1;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> x;
            c[i].insert(mn(x));
        }
    }
    cin >> n;
    getline(cin,x);
    for(int i=0;i<n;i++){
        int ch[2] = {0};
        bool ok = false;
        getline(cin,x);
        vector<string> f;
        string cur;
        for(int j=0;j<x.size();j++){
            if(x[j] == ' ') f.pb(mn(cur)), cur.clear();
            else cur += x[j];
        }
        f.pb(mn(cur)), cur.clear();
        for(int j=0;j<f.size();j++){
            if(f[j] == p) ok = true;
            if(c[0].count(f[j])) ch[0]++;
            if(c[1].count(f[j])) ch[1]++;
        }
        if(ok){
            if(ch[0] - ch[1] > 0) ans[0]++;
            else if(ch[0] - ch[1] == 0) ans[1]++;
            else ans[2]++; 
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    return 0;
}