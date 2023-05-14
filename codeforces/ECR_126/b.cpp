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
const int INF = 0x3f3f3f3f, MOD = 32768;
const int N = 1e5+5;

int ans;

int calc(int u){
    if(!u) return 0;
    int cnt = 0;
    while(!(u%2) and u){
        u /= 2;
        cnt++;
    }
    return (15 - cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans = 15;
        int acc = 0;
        for(int j = 0; j <= 15; j++){
            int cur = (x + j) % MOD;
            ans = min(ans, calc(cur) + j);
        }
        cout << ans << " ";
    }
    return 0;
}