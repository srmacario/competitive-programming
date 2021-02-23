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
const int N = 3e4+5;

int a[N];
pii r[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
            r[a[i]%3].st++;
        }
        r[0].nd = 0, r[1].nd = 1, r[2].nd = 2;
        int ans = 0;
        for(int i=0;i<3;i++){
            //db(r[0].st _ r[1].st _ r[2].st);
            pii mx = max({r[0],r[1],r[2]});
            if(mx.st == n/3) break;
            else{
                int dif = mx.st-n/3;
                ans += dif;
                r[mx.nd].st -= dif;
                r[(mx.nd+1)%3].st += dif;
            }
        }
        memset(r,0,sizeof(r));
        cout << ans << "\n";
    }
    return 0;
}