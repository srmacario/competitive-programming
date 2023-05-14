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

map <int,int> mapid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <vi> freq;
        vector<pii> sum;
        vi id;
        sum.resize((k+1)/2);
        id.resize(n);
        for(int i=0;i<=(k-1)/2;i++){
            id[i] = i;
            vi f;
            for(int j=0;j<26;j++) f.pb(0);
            freq.pb(f);
        }
        int cnt = 0;
        for(int i=k-1;i>(k-1)/2;i--){
            id[i] = cnt;
            cnt++;
        }
        for(int j=0;j<n;j++){
            freq[id[j%k]][s[j]-'a']++, sum[id[j%k]].st++, sum[id[j%k]].nd = max(sum[id[j%k]].nd,freq[id[j%k]][s[j]-'a']);
        }
        ll ans = 0;
        for(int i=0;i<=(k-1)/2;i++){
            ans += sum[i].st - sum[i].nd;
        }
        cout << ans << "\n";
    }
    return 0;
}