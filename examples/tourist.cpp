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

int n,v;
vector <pii> e;

int lis(){
    vi v;
    for(int i=0;i<n;i++){
        int x = e[i].nd;
        if(v.empty() or x >= v.back()) v.pb(x);
        else{
            int pos = upper_bound(v.begin(), v.end(), x) - v.begin();
            v[pos]  = x;
        }
    }
    return v.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans[2];
    cin >> n;
    for(int i=0;i<n;i++){
        int x,t;
        cin >> x >> t;
        e.pb({x,t});
    }
    cin >> v;
    for(int i=0;i<n;i++){
        int x = e[i].st,t = e[i].nd;
        e[i].st = -x + v*t;
        e[i].nd = x + v*t;
    }
    sort(e.begin(), e.end());
    ans[1] = lis();
    vector<pii> aux;
    aux.pb({0,0});
    for(int i=0;i<n;i++){
        if(aux[0].st <= e[i].st and aux[0].nd <= e[i].nd) aux.pb(e[i]);
    }
    e = aux;
    n = e.size();
    ans[0] = lis() - 1;
    cout << ans[0] << " "<< ans[1] << "\n";
    return 0;
}