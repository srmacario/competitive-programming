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
const int N = 2e5+5;

ll n, k, pos[N], l, r, cur;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    l = 1, r = n;
    // db(l _ r);
    while(k and k >= r - 1){
        pos[l++] = r--;
        k -= r;
    }
    if(k) pos[l++] = k + 1;
    for(int i = 1; i <= r; i++){
        if(k and i == k + 1) continue;
        pos[l++] = i;
    }
    for(int i = 1; i <= n; i++) cout << pos[i] << " ";
    cout << "\n";
    return 0;
}