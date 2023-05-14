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
const int N = 2e6+5;
const int M = 1e6;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("boolean.in", "r", stdin);
    freopen("boolean.out", "w", stdout);
    string s;
    cin >> s;
    bool ok = true;
    int var[100];
    memset(var,-1,sizeof(var));
    int neg = 0, sub = 1;
    for(int i=0;i<s.size();i++){
        if(s[i] == '|') {neg = 0; continue;}
        else if(s[i] == '~'){neg = 1; continue;}
        else{
            int cur = !neg;
            db(s[i] - 'A');
            db(var[s[i]- 'A']), db(cur);
            if(~var[s[i] - 'A'] and var[s[i] - 'A'] != cur) sub = 0;
            var[s[i] - 'A'] = cur;
        }
    }
    ll ans = 1;
    for(int i=0;i<100;i++) if(~var[i]) ans *= 2;
    cout << (ok ? ans - sub: 0) << "\n";
    return 0;
}