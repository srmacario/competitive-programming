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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        int n,q;
        cin >> n >> q >> s;
        s = "$" + s;
        int ps[2][105];
        memset(ps,0,sizeof(ps));
        for(int i=1;i<=n;i++){
            ps[0][i] = ps[0][i-1];
            ps[1][i] = ps[1][i-1];
            ps[s[i]-'0'][i]++;
        }
        /*for(int j=0;j<2;j++){
            for(int i=1;i<=n;i++){
                cout << ps[j][i] << " ";
            }
            cout << "\n";
        }*/
        for(int i=0;i<q;i++){
            bool ok = false;
            int l,r;
            cin >> l >> r;
            if(ps[s[l]-'0'][l-1] > 0) ok = true;
            if(ps[s[r]-'0'][n] - ps[s[r] - '0'][r] > 0) ok = true;
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}