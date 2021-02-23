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
        ll n,W;
        cin >> n >> W;
        vector <pll> bag(n);
        for(int i=0;i<n;i++){
            cin >> bag[i].st;
            bag[i].nd = i;
        }
        sort(bag.begin(),bag.end(),greater<pll>());
        ll cur = 0;
        vector<ll> ans;
        for(int i=0;i<bag.size();i++){
            if(cur + bag[i].st > W) continue;
            ans.pb(bag[i].nd);
            cur += bag[i].st;
            if(cur >= ((W+1)/2)) break;
        }
        if(cur < ((W+1)/2)) ans.clear();
        if(ans.size()){
            sort(ans.begin(),ans.end());
            cout << ans.size() << "\n";
            for(int i=0;i<ans.size();i++) cout << ans[i]+1 << " ";
        }
        else cout << "-1";
        cout << "\n";
    }
    return 0;
}