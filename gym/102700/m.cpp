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

vi pos[26];

int lowe (int l, int r, int targ, int dig) {
    int m;
    while (l < r) {
        m = (l+r)/2;
        if (pos[dig][m] < targ) l = m+1;
        else r = m;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin >> s >> n;
    for(int i=0;i<s.size();i++){
        pos[s[i] - 'a'].pb(i);
    }
    for(int i=0;i<n;i++){
        string tmp, ans;
        cin >> tmp;
        int cur = 0;
        for(int j=0;j<tmp.size();j++){
            int l = 0;
            int r = pos[tmp[j] - 'a'].size() - 1;
            if(l > r) break;
            int nxt = lowe(l,r,cur,tmp[j]-'a');
            if(nxt == r){
                if(pos[tmp[j]-'a'][nxt] < cur) break;
            }
            ans += tmp[j];
            cur = pos[tmp[j] - 'a'][nxt]+1;
        }
        if(!ans.size()) ans = "IMPOSSIBLE";
        cout << ans << "\n";
    }
    return 0;
}