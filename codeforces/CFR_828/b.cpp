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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        ll sum[2] = {0}, cnt[2] = {0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum[a[i] % 2] += a[i];
            cnt[a[i] % 2] ++;
        }
        for(int i = 0; i < q; i++){
            int op, x;
            cin >> op >> x;
            if(!op){
                if(x % 2){
                    sum[1] += sum[0] + x * cnt[0];
                    cnt[1] += cnt[0];
                    sum[0] = cnt[0] = 0;
                }
                else sum[0] += cnt[0] * x;
            }
            if(op){
                if(x % 2){
                    sum[0] += sum[1] + x * cnt[1];
                    cnt[0] += cnt[1];
                    sum[1] = cnt[1] = 0;
                }
                else sum[1] += cnt[1] * x;
            }
            cout << (sum[1] + sum[0]) << "\n";
        }
    }
    return 0;
}