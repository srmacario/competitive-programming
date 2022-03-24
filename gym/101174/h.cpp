#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e6 + 3;
const int N = 1e5 + 5;

int d, h, sum;
vector<int> v;
map<vector<int>, ll> dp;
set<ll> s;

void calc2(){
    vector<int> vaux = v;
    for(int i = 0, j = 0; i < d; j++, i = j){
        if(v[i]){
            vaux[i]--;
            while(j + 1 < d && v[i] == v[j + 1])
                j++;
            dp[v] += dp[vaux] * (j - i + 1);
            vaux[i]++;
        }
    }
    if(sum == 0)
        dp[v] = 1;
    if(sum == h - 1)
        s.insert(dp[v]);
}

void calc(int p, int pp){
    if(sum + pp * (d - p) >= h)
        return;
    if(p == d)
        calc2();
    else{
        for(int i = pp; i < h; i++){
            sum += i;
            v[p] = i;
            calc(p + 1, i);
            sum -= i;
        }
    }
}

int main(){
    scanf("%d %d", &d, &h);
    v.resize(d);
    calc(0, 0);
    for(ll i : s)
        printf("%lld\n", i);
    return 0;
}