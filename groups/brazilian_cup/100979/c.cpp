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

ll k,n,q;
ll ans;
ll busca(){
    ll l = 1, r = n;
    while(l < r){
        ll m = (l+r)/2;
        ll sum = ((n + m)*(n-m+1))/2;
        if(sum < q) r = m;
        else l = m+1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i=0;i<k;i++){ 
        cin >> n >> q;
        if(n >= q) cout << "1\n";
        else{
            ll l = busca();
            ans = (n - l + 1);
            q -= ((n+l)*(n-l+1))/2;
            n = l-1;
            if(n) cout << ++ans << "\n";
            else cout << "IMPOSSIVEL\n";
        }
    }
    return 0;
}