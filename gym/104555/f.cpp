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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, n[2];
    cin >> d >> n[0] >> n[1];
    vector<int> act[2];
    for(int i = 0; i < 2; i++){
        act[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++){
            cin >> act[i][j];
        }
    }
    int ans = 0, ok = 1, i = 0, j = 0;
    while(ok){
        if(i < n[0] and d >= act[0][i]){
            ans++;
            d -= act[0][i++];
            continue;
        }
        if(j < n[1]){
            ans++;
            d += act[1][j++];
            continue;
        }
        break;
    }
    cout << ans << "\n";
    return 0;
}