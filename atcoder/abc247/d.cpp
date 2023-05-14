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

ll x[N], c[N], l, r, rem, rem_sum;
ll ps[N];

ll calc(ll qry){
    int cur_l = l - 1, cur_r = r - 1;
    while(cur_l < cur_r){
        int mid = (cur_l + cur_r + 1)/2;
        if(c[mid] - c[l - 1] - rem <= qry) cur_l = mid;
        else cur_r = mid - 1;
    }
    return cur_l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    l = 1, r = 1;
    for(int i = 1; i <= q; i++){
        int op;
        cin >> op;
        if(op == 1){
            cin >> x[r] >> c[r];
            r++;
        }
        if(op == 2){
            ll qry, ans = 0;
            cin >> qry;
            for(int j = l; j < r; j++){
                if(qry >= c[j]){
                    ans = (ans + (c[j] * x[j]));
                    qry -= c[j];
                    l++;
                }
                else{
                    ans = (ans + (qry * x[j]));
                    c[j] -= qry;
                    qry = 0;
                }
                if(!qry) break;
            }
            cout << (ans) << "\n";
        }
    }
    return 0;
}