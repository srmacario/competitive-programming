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

int n, dist[N], par[N];
vi a[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s == "cube"){
            a[0].pb(x);
        }
        else{
            a[1].pb(x);
        }
    }
    sort(a[0].begin(), a[0].end(), greater<int>());
    sort(a[1].begin(), a[1].end(), greater<int>());
    int l = 0, r = 0;
    vector <pair<string, int>> ans;
    while(l < a[0].size() or r < a[1].size()){
        if(l == a[0].size()){
            ans.pb({"cylinder", a[1][r++]});
        }
        else if(r == a[1].size()){
            ans.pb({"cube", a[0][l++]});
        }
        else if(a[0][l] >= 2 * a[1][r]){
            ans.pb({"cube", a[0][l++]});
        }
        else if(4*a[1][r]*a[1][r] >= 2*a[0][l]*a[0][l]){
            ans.pb({"cylinder", a[1][r++]});
        }
        else{
            cout << "impossible\n";
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto p : ans){
        cout << p.st << " " << p.nd << "\n";
    }
    return 0;
}