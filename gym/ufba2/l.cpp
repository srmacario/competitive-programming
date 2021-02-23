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
typedef pair<ld,int> pldi;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
ll W, w[N], v[N];
vector<plll> big;
vector<pair<pldi,pll>> small;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> W;
        big.clear(), small.clear();
        for(int i=0;i<n;i++){
            cin >> w[i] >> v[i];
            if(2*w[i] > W) big.pb({w[i],{v[i],i}});
            else small.pb({{ld(v[i])/w[i],-w[i]},{v[i],i}});
        }
        sort(big.begin(),big.end(),greater<plll>());
        sort(small.begin(),small.end(),greater<pair<pldi,pll>>());
        ll peso = 0, sum = 0, ans = 0, bg = -1, sz = 0, l = 0, r = 0;
        vi items;
        for(l=0,r=0;l<big.size();l++){
            if(big[l].nd.st > ans and 2*big[l].st <= 3*W){
                bg = big[l].nd.nd;
                ans = big[l].nd.st;
                sz = 0;
            } 
            while(2*peso + 2*big[l].st <= 3*W and r < small.size()){
                peso += -small[r].st.nd;
                sum += small[r].nd.st;
                items.pb(small[r].nd.nd);
                r++;
            }
            if(sum + big[l].nd.st > ans and 2*peso + 2*big[l].st <= 3*W){
                sz = items.size();
                bg = big[l].nd.nd;
                ans = sum + big[l].nd.st;
            }
        }
        while(2*peso <= 3*W and r < small.size()){
            peso += -small[r].st.nd;
            sum += small[r].nd.st;
            items.pb(small[r].nd.nd);
            r++;
        }
        if(sum > ans){
            sz = items.size();
            bg = -1;
        }
        cout << items.size() + (bg >= 0) << "\n";
        for(int i=0;i<sz;i++){
            cout << items[i] + 1 << " ";
        }
        if(bg >= 0) cout << bg+1;
        cout << "\n";
    }
    return 0;
}