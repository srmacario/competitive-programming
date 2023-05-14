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

ll n, m, a[N]; 

bool possible(ll k){
    vector <ll> freq;
    for(int i=0;i<k+5;i++) freq.pb(0);
    for(ll i=1;i<n;i++){
        vector <ll> aux;
        for(int i=0;i<k+5;i++) aux.pb(0);
        for(ll j = a[i]; j<a[i+1]; j++){
            if(i == 1) freq[j%k] = 1;
            else freq[j%k]aux[j%k] = 1;
        }
        if(i == 1){
            freq = aux;
        }
        else{
            for(ll j=0;j<k;j++){
                freq[j] &= aux[j];
            }
        }
    }
    vector <ll> aux;
    for(int i=0;i<k+5;i++) aux.pb(0);
    for(ll j = a[n]; j<=m; j++){
        aux[j%k] = 1;
    }
    for(ll j=0;j<k;j++){
        freq[j] &= aux[j];
        if(freq[j]) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll l = 1, r = m+5;
    //for(int i=1;i<=m;i++) cout << possible(i) << "\n";
    while(l<=r){
        ll mid = (l+r)/2;
        if(possible(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << "\nI";
    return 0;
}