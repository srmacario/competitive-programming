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
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        vi s(m);
        for(int i=0;i<m;i++) cin >> s[i];
        sort(s.begin(),s.end(),greater<int>());
        int pos = abs(b-a)-1;
        int ans = 0;
        int dif;
        if(a<b) dif = b-1;
        else dif = n-b;
        for(int i=0;i<s.size();i++){
            if(!pos) break;
            if(s[i] < dif) ans++, pos--, dif--;
        }
        cout << ans << "\n";
    }
    return 0;
}