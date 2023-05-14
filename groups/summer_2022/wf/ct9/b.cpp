#include <bits/stdc++.h>

using namespace std;

#define st firs
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long type;

ll a[N];
map<ll,ll> gr;

ll calc(ll x){
    if(x == 1) return gr[x] = 1;
    if(x == 0) return gr[x] = 0;
    if(gr.count(x)) return gr[x];
    set<ll> num;
    for(int i = 2; i <= 6; i++){
        num.insert(calc(x/i));
    }
    ll mex = 0;
    for(auto i : num){
        if(i == mex) mex++;
        else{
            gr[x] = mex;
            return gr[x];
        }
    }
    gr[x] = mex;
    return gr[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = 0;
        int ok = 1;
        
        for(int i = 0; i <= 500; i++){
            ll k = calc(i);
            if(k == 3) cout << i << " ";
        }
    }
    return 0;
}