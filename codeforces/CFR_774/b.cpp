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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll sum_l = v[0] + v[1], cnt_l = 2;
        ll sum_r = v.back(), cnt_r = 1;
        bool ok = false;
        for(int l = 2, r = n - 2; l < r; l++){
            if(sum_r > sum_l){
                ok = true;
                break;
            }
            sum_l += v[l];
            cnt_l++;
            sum_r += v[r];
            cnt_r++;
            r--;
        }
        if(sum_r > sum_l){
            ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}