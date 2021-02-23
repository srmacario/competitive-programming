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
        vector<ll> a;
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            if(i==0 or i==n-1) a.pb(x);
            a.pb(x);
        }
        vi s(n);
        for(int i=0;i<n+2;i++) s.pb(0); 
        int ans = 0, cnt = 0, dif = 0;
        for(int i=1;i<=n;i++){
            if((a[i] > a[i-1]) and (a[i] > a[i+1])) s[i] = 1, ans++;
            if((a[i] < a[i-1]) and (a[i] < a[i+1])) s[i] = 1, ans++;
        }
        int resp = ans;
        for(int i=2;i<n;i++){
            if(!s[i]) continue;
            int cur = a[i-1];
            int lst = 0, nxt = 0;
            int dif = -1;
            if((a[i-1] > cur) and (a[i-1] > a[i-2])) lst = 1;
            if((a[i-1] < cur) and (a[i-1] < a[i-2])) lst = 1;

            if((a[i+1] > cur) and (a[i+1] > a[i+2])) nxt = 1;
            if((a[i+1] < cur) and (a[i+1] < a[i+2])) nxt = 1;
            if(!s[i-1] and lst) dif++;
            if(s[i-1] and !lst) dif--;
            if(!s[i+1] and nxt) dif++;
            if(s[i+1] and !nxt) dif--;
            int partans = ans+dif;
            resp = min(resp,partans);
            
            dif = -1;
            cur = a[i+1];
            lst = 0, nxt = 0;
            if((a[i-1] > cur) and (a[i-1] > a[i-2])) lst = 1;
            if((a[i-1] < cur) and (a[i-1] < a[i-2])) lst = 1;

            if((a[i+1] > cur) and (a[i+1] > a[i+2])) nxt = 1;
            if((a[i+1] < cur) and (a[i+1] < a[i+2])) nxt = 1;
            if(!s[i-1] and lst) dif++;
            if(s[i-1] and !lst) dif--;
            if(!s[i+1] and nxt) dif++;
            if(s[i+1] and !nxt) dif--;
            partans = ans+dif;
            resp = min(resp,partans);
        }
        cout << resp << "\n";
    }
    return 0;
}