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
const int N = 1e5+5;

int a[N], pre[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i-1]^a[i];
            // db(pre[i]);
        }
        bool ok = false;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                int l = pre[i];
                int mid = pre[j-1]^pre[i];
                int r = pre[n]^pre[j-1];
                if((l == r) and (mid == 0 or mid == l)) ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}