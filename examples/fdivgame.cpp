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
map<ll,ll> memo;

ll gr(ll num){
    if(!num) return 0;
    if(memo.count(num)) return memo[num];
    vector<ll> state;
    for(ll i=2;i<=6;i++){
        state.pb(gr(num/i));
    }
    sort(state.begin(),state.end());
    ll mex = 0;
    //cout << num << ": ";
    for(int i=0;i<5;i++){
        //cout << state[i] << " ";
        if(state[i] == mex) mex++;
    }
    //cout << "\n";
    return memo[num] = mex;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll game, ans;
        for(int i=1;i<=n;i++){
            // ll num;
            // cin >> num;
            game = gr(i);
            cout << game << " ";
            if(!i) ans = game;
            else ans ^= game;
        }
        cout << (ans ? "Henry" : "Derek") << "\n";
    }
    return 0;
}