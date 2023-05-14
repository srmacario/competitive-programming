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
const int N = 1e5+5, M = 1e5;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll k;
    scanf("%lld", &k);
    if(k == 1){
        printf("1\n1\n");
        return 0;
    }
    vector<ll> div, ans;
    ll sum = 0;
    bool ok = true;
    for(ll i = 2; i < N; i++){
        if(k == 1) break;
        ll p = 1;
        if(!(k%i)){
            while(!(k%i)) k /= i, p *= i;
            div.pb(p);
            sum += p;
        }
    }
    if(k != 1) sum += k;
    if(sum > M) ok = false;
    if(ok){
        printf("%lld\n", sum);
        for(int i = 1; i <= sum; i++){
            ans.pb(i);
        }
        int pos = 0;
        for(auto d : div){
            for(int i = pos; i < pos + d-1; i++) swap(ans[i], ans[i+1]);
            pos += d;
        }
        for(auto x : ans) printf("%lld ", x);
        printf("\n");
    }
    else printf("No solution\n");
    return 0;
}