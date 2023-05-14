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

int n, m;
set<int> s[15];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int a;
            cin >> a;
            s[i].insert(a);
        }
    }
    int tot = 0;
    for(int i = 1; i < (1 << m); i++){
        set<int> ans;
        for(int j = 0; j < m; j++){
            if((i & (1 << j))){
                for(auto u : s[j]) ans.insert(u);
            }
        }
        if(ans.size() == n) tot++;
    }
    cout << tot << "\n";
    return 0;
}