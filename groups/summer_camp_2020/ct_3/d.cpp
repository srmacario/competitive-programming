#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll solve(ll x){
    ll d = 0, aux = x, pot = 1, ans = 0;
    while(aux){
        d++;
        aux/=10;
    }
    for(int j=1;j<=d;j++){
        ll c = (x/pot)%10;
        for(int i=1;i<=9;i++){
            if(i<c) ans += ((x-1)/(10*pot) + 1)*pot*i;
            else if(i==c) ans += i*((x/(10*pot))*(pot) + (x%(pot) + 1));
            else ans += i*((x/(10*pot))*pot);
        }
        pot*=10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll i;
        cout << solve(b) - solve(a-1) << "\n";
    }
    return 0;
}