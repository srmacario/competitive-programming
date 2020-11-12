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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        bool ok = false;
        int r,g,b,w;
        cin >> r >> g >> b >> w;
        int cnt = 0;
        if(r%2) cnt++;
        if(g%2) cnt++;
        if(b%2) cnt++;
        if(w%2) cnt++;
        //cout << cnt << "\n";
        if(cnt <= 1){
            ok = true;
        }
        else if(r and g and b){
            cnt = 0;
            r--,g--,b--,w+=3;
            if(r%2) cnt++;
            if(g%2) cnt++;
            if(b%2) cnt++;
            if(w%2) cnt++;
            if(cnt <= 1){
                ok = true;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}