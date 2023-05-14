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
        bool ok = true;
        int c[4], a[6];
        for(int i=1;i<=3;i++) cin >> c[i];
        for(int i=1;i<=5;i++) cin >> a[i];
        for(int i=1;i<=3;i++){
            if(a[i] > c[i]){
                ok = false;
                break;
            }
            else c[i] -= a[i];
        }
        for(int i=0;i<2;i++){
            if(a[4+i] > c[1+i]) a[4+i] -= c[1+i], c[i+1] = 0;
            else c[1+i]-=a[4+i], a[4+i] = 0;
        }
        //db(c[3] _ a[4] _ a[5]);
        if(c[3] < a[4] + a[5]) ok = false;
        cout << (ok ? "YES" : "NO") << "\n"; 
    }
    return 0;
}