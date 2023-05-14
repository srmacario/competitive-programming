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

int a[N], no[N], ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set <int> s[2];
    for(int i = 1; i <= ((n+1)/2); i++){
        cout << "Q " << i << " " << i+(n+1)/2-1 << endl;
        s[i&1].clear();
        for(int j = 1; j <= (n+1)/2; j++){
            int x;
            cin >> x;
            if(i > 1) {
                if(!s[(i&1)^1].count(x)) ans[i+(n+1)/2-1] = x, no[x] = 1;
                else s[(i&1)^1].erase(x);
            }
            s[i&1].insert(x);
        }
        if(s[(i&1)^1].size()) ans[i-1] = *s[(i&1)^1].begin(), no[*s[(i&1)^1].begin()] = 1; 
    }
    for(int i = 1; i <= n; i++){
        if(!no[i]){
            if( s[((n+1)/2) & 1].count(i)) ans[(n+1)/2] = i;
            else ans[n] = i;
            no[i] = 1;
        }
    }
    cout << "A ";
    for(int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << ans[n] << "\n";
    return 0;
}