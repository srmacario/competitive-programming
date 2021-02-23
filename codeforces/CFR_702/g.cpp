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
const int N = 2e5+5;

ll a[N], ps[N];
map<ll,ll> mp;
set<ll> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        pll mx = {0,0};
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ps[i] = a[i] + ps[i-1];
            if(!mp.count(ps[i])) mp[ps[i]] = i-1;
            s.insert(ps[i]);
            if(ps[i] > mx.st) mx = {ps[i],i-1};
        }
        s.insert(LINF);
        for(int i=0;i<m;i++){
            ll x;
            cin >> x;
            int pos = distance(s.begin(),lower_bound(s.begin(),s.end(),x));
            //db(pos);
            if(pos == s.size()-1){
                if(ps[n] <= 0) cout << "-1 ";
                else{
                    ll k = (x-mx.st-1)/ps[n]+1;
                    x -= k*ps[n];
                    pos = mp[*(lower_bound(s.begin(),s.end(),x))];
                    db(mx.st _ x _ k _ pos);
                    cout << k*n + pos << " ";
                }
            }
            else{
                cout << mp[*(lower_bound(s.begin(),s.end(),x))] << " ";
            }
        }
        cout << "\n";

        for(int i=0;i<=n;i++) a[i] = ps[i] = 0;
        mp.clear();
        s.clear();
    }
    return 0;
}