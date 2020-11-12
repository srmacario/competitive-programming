#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
        int n,k, gk = 0, lk = 0, nk = 0, block = 0;
        cin >> n >> k;
        vi a(n+5), num, ps(n+5);
        for(int i=0;i<n+5;i++) ps[i] = a[i] = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            if(a[i] == k) nk++;
            if(a[i] < k) lk++;
            ps[i] = ps[i-1] + (a[i] < k ? 0 : 1);
        }
        for(int i=0;i<=n-3;i++){
            //db(ps[i+3] - ps[i]);
            if(ps[i+3] - ps[i] >= 2) block++;
        }
        //db(gk), db(lk);
        if(!nk){
            cout << "no\n";
            continue;
        }
        if(n == 1){
            cout << "yes\n";
            continue;
        }
        if(n == 2){
            cout << (lk ? "no" : "yes") << "\n";
            continue;
        }
        cout << (block ? "yes" : "no") << "\n";
    }    
    return 0;
}