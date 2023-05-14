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
const int N = 3e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pii> a(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[i] = {x, i};
        }
        sort(a.begin(), a.end());
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(a[i].nd != a[i - 1].nd + 1){
                ans++;
            }
            // cout << a[i].st << " " << a[i].nd << "\n";
        }
        if(ans <= k) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}