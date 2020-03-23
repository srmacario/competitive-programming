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
const int N = 2e5+5;

int st[4*N], v[N], u[N], ans[N], n;
vector<pll> seg;
vector <pair<ll,pll>> num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        ll l,r;
        cin >> l >> r;
        seg.pb({l,r});
        num.pb({l,{0,i}}), num.pb({r,{1,i}});
    }
    sort(num.begin(),num.end());
    ll cnt = 1, carry = num[0].st;
    num[0].st = 1;
    for(int i=1;i<num.size();i++){
        if(num[i].st == carry) carry = num[i].st, num[i].st = cnt;
        else carry = num[i].st, num[i].st = ++cnt;
    }
    for(int i=0;i<num.size();i++){
        ll id = num[i].nd.nd;
        if(num[i].nd.st) seg[id].nd = num[i].st;
        else seg[id].st = num[i].st;
    }
    for(int i=0;i<seg.size();i++){
       v[seg[i].st]++, u[seg[i].nd]++;
    }
    /*for(int i=1;i<=2*n;i++){
       v[i] += v[i-1];
       u[i] += u[i-1];
    }*/
    for(int i=1;i<=2*n;i++){
       cout << v[i] << " ";
    }
    cout << "\n";
    for(int i=1;i<=2*n;i++){
       cout << u[i] << " ";
    }
    ll l = 0, r = 0;
    for(int i=1;i<=2*n;i++){
        l += v[i];
        r += u[i];
        if(r){
            ans[i]+=r;
            l-=r;
            r=0;
        }
    }
    cout << "\n";
    return 0;
}