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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        priority_queue<ll> pq;
        ll need = 0;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            pq.push(x);
        }
        need = 2ll * pq.top() + 1;
        pq.pop();
        while(pq.size() > 1){
            need += pq.top() + 1ll;
            pq.pop();
        }
        need++;
        cout << ((need <= m) ? "YES\n" : "NO\n");
    }
    return 0;
}