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

ll x, y, ans = 0;

void rec(ll num, ll n, ll m, ll lvl, ll bits){
    ll aux;
    if(lvl){
        bits += m;
        if(bits > 63) return;
        aux = (num << m);
    }
    else{
        bits += n;
        if(bits > 63) return;
        aux = (num << n);
        aux += (1ll<<(n)) - 1;
    }
    if(aux > y) return;
    if(aux <= y and aux >= x){
        ans++;
        //cout << aux << "\n";
    }
    rec(aux,n,m,lvl^1,bits);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    for(ll i=1;i<=63;i++){
        ll num1 = (1ll<<(i)) - 1;
        if(num1 > y) break;
        if(num1 <= y and num1 >= x){
            ans++;
            //cout << num1 << " ";
        }
        for(ll j=1;j+i<=63;j++){
            ll num2 = (num1 << j);
            if(num2 > y) break;
            if(num2 <= y and num2 >= x){
                ans++;
                //cout << num2 << "\n";
            }
            rec(num2,i,j,0,j+i);
        }
    }
    cout << ans << "\n";
    return 0;
}