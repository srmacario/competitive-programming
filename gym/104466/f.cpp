#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int w, h;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    v.resize(w);
    for(int i = 0; i < w; i++)
        cin >> v[i];
    int cnt = 0;
    for(int i = 0; i < w; i++){
        int r = h - v[i] - cnt;
        if(r < 0){
            cout << "impossible\n";
            return 0;
        }
        if(r % 2) cnt++;
        else{
            cnt = max(0, cnt - 1);
        }
    }
    if(cnt) cout << "impossible\n";
    else cout << "possible\n";
    return 0;
}