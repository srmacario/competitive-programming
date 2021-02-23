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

vi Z (string &q) {
    vi z(q.size());
    for (int i = 1, l = 0, r = 0, n = q.size(); i < n; i++) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n and q[z[i]] == q[z[i] + i]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t,revs,revt;
    cin >> s >> t;
    int S = s.size(), T = t.size();
    bool ok = false;
        if(S == T){
        vi z, revz;  
        revs = s, revt = t;  
        reverse(revs.begin(),revs.end());
        reverse(revt.begin(),revt.end());
        s += "$" + revt;
        t += "$" + s;
        int ans = 0;
        z = Z(t), revz = Z(s);
        for(int i=0;i<=revz[S+1];i++){
            if(z[S+1+i] == S-i){
                ok = true;
                ans = i;
                break;
            }
        }
        if(ok) cout << "Yes\n" << ans;
        else cout << "No";
        cout << "\n";
    }
    return 0;
}