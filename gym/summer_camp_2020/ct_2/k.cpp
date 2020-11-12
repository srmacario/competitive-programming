#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

ll n, k, a[N];

ll gr(ll x){
    if(k%2){
        if(x <= 3) return(x%2 ? 1 : 0);
        if(x == 4) return 2;
        if(x%2) return 0;
        return (gr(x/2) == 1 ? 2 : 1);
    }
    else{
        if(x == 1) return 1;
        else if(x == 2) return 2;
        else return(x%2 ? 0 : 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ans = ans^gr(a[i]);
    }
    cout << (ans ? "Kevin\n" : "Nicky\n");
    return 0;
}