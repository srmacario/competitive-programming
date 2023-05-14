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
const int N = 1e5+5, M = 1e3 + 5;

int n, s, a[N], sum[M], ans = INF;

void add(int x){
    for(int i = M - 1; i >= 0; i--){
        if(i + x < M) sum[i + x] += sum[i];
    }
}

void remove(int x){
    for(int i = 0; i < M; i++){
        if(i + x < M) sum[i + x] -= sum[i];
    }
}

int main(){
    sum[0] = 1;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int l = 0, r = 0; r < n; r++){
        add(a[r]);
        while(sum[s]){
            ans = min(ans, r - l + 1);
            remove(a[l++]);
        }
    }
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}