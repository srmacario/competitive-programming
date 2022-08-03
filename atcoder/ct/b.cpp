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
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set<int> s;
    for(int i = 0; i < n; i++){
        if(v[i] <= w) s.insert(v[i]);
        for(int j = i + 1; j < n; j++){
            if(v[i] + v[j] <= w) s.insert(v[i] + v[j]);
            for(int k = j + 1; k < n; k++){
                if(v[i] + v[j] + v[k] <= w) s.insert(v[i] + v[j] + v[k]);
            }
        }
    }
    cout << s.size() << "\n";
    return 0;
}