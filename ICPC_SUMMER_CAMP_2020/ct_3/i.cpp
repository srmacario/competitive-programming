#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        deque <ll> d;
        string p;
        ll n;
        cin >> p >> n;
        if(!n){
            bool b = true;
            string trash;
            cin >> trash;
            for(int i=0;i<p.size();i++){
                if(p[i] == 'D') b = false;
            }
            if(b) cout << "[]\n";
            else cout << "error\n";
            continue;
        }
        for(int i=0;i<=2*n;i++){
            ll x;
            char c;
            if(i%2) cin >> x, d.push_front(x);
            else cin >> c;
        }
        bool s = true, ok = true;
        for(int i=0;i<p.size();i++){
            if(p[i] == 'D'){
                if(!d.size()){
                    ok = false;
                    break;
                }
                if(s) d.pop_back();
                else d.pop_front();
            }
            else s = !s;
        }
        if(ok){
            if(s) reverse(d.begin(), d.end());
            cout << "[";
            for(int i=0;i<d.size();i++){
                cout << d[i];
                if(i != d.size()-1) cout << ",";
            }
            cout << "]\n";
        }
        else cout << "error\n";
    }
    return 0;
}