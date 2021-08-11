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

int n, p, cur, q;
vi l, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    for(int i = 1; i < p; i++){
        int x;
        cin >> x;
        l.pb(x);
    }
    cin >> cur;
    for(int i = p + 1; i <= n; i++){
        int x;
        cin >> x;
        r.pb(x);
    }
    reverse(r.begin(), r.end());
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        if(s == "print") cout << cur << "\n";
        if(s == "moveRight"){
            if(r.size()){
                l.pb(cur);
                cur = r[r.size() - 1];
                r.pop_back();
            }
        }
        if(s == "moveLeft"){
            if(l.size()){
                r.pb(cur);
                cur = l[l.size()-1];
                l.pop_back();
            }
        }
        if(s == "insertRight"){
            int x;
            cin >> x;
            r.pb(x);
        }
        if(s == "insertLeft"){
            int x;
            cin >> x;
            l.pb(x);
        }
    }
    return 0;
}