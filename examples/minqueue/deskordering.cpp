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
const int N = 1e6+5;

ll n, m, a[N], mx[N], ndmx[N];

struct maxQueue{
    stack <pair<ll,pll>> s1, s2;
    void push(ll x){
        if(!s1.size()) s1.push({x,{x,-1}});
        else{
            pair <ll,pll> tp = s1.top();
            ll smx = tp.nd.st, sndmx = tp.nd.nd;
            if(x >= tp.nd.st) sndmx = tp.nd.st, smx = x;
            if(x < tp.nd.st and x>=tp.nd.nd) sndmx = x;
            s1.push({x,{smx,sndmx}});
        }
    }
    void pop(){
        if(!s2.size()){
            ll x = s1.top().st;
            s2.push({x,{x,-1}});
            s1.pop();
            while(s1.size()){
                pair <ll,pll> tp = s2.top();
                ll x = s1.top().st;
                ll smx = tp.nd.st, sndmx = tp.nd.nd;
                if(x >= tp.nd.st) sndmx = tp.nd.st, smx = x;
                if(x < tp.nd.st and x >= tp.nd.nd) sndmx = x;
                s2.push({x,{smx,sndmx}});
                s1.pop();
            }
        }
        s2.pop();
    }
    pll query(){
        ll v[4] = {-1,-1,-1,-1};
        if(s1.size()){
            v[0] = s1.top().nd.st;
            v[1] = s1.top().nd.nd;
        }
        if(s2.size()){
            v[2] = s2.top().nd.st;
            v[3] = s2.top().nd.nd;
        }
        sort(v,v+4);
        return {v[3],v[2]};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    maxQueue mxq;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for(ll l = 1;l<=m;l++) mxq.push(a[l]);
    ll delta = LINF;
    for(ll l = 1;l<=n - m + 1;l++){
        ll r = l + m - 1, dx;
        pll ans = mxq.query();
        dx = ans.st - ans.nd;
        delta = min(dx,delta);
        mxq.pop();
        if(r!=n) mxq.push(a[r+1]);
    }
    cout << delta/2 << "\n";
    return 0;
}