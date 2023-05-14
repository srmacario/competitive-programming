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
const int N = 2e5+5;

int n;
ll p[N], x[N], sp[N];
pair<string, int> s[N];

bool cmp(pair<string, int> a, pair<string, int> b){
    return p[a.nd] * x[b.nd] < p[b.nd] * x[a.nd];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i].st;
        s[i].nd = i;
        for(auto ch : s[i].st){
            if(ch == 'X') x[i]++;
            else{
                p[i] += ch - '0';
                sp[i] += (x[i]) * (ch - '0');
            }
        }
    }
    sort(s, s + n, cmp);
    ll cnt = 0, ans = 0;
    for(int i = 0; i < n; i++){
        for(auto ch : s[i].st){
            if(ch == 'X'){
                cnt++;
            }
            else{
                ans += (cnt * (ch - '0'));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}