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
const int N = 2e5+5;

int n, a[N], ing[N], ans[N], vis[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ing[a[i]]++;
    }
    int resp = 0;
    for(int i = 1; i <= n; i++){
        int cur = i;
        while(vis[cur] == 0 or vis[cur] == i){
            if(vis[cur] == i) vis[cur] = -1, resp++;
            else vis[cur] = i;
            cur = a[cur];
        }
    }
    cout << resp << "\n";
    return 0;
}