#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n){
        int t = 0,m = 0,b = 0, ans = 0;
        for(int i=0;i<n;i++){
            string s,r;
            cin >> s;
            int cnt = 0;
            for(int j=0;j<s.size();j++){
                if(s[j] == 'D' or s[j] == 'R') r+=s[j],cnt++;
            }
            for(int j=1;j<r.size();j++){
                if(r[j-1] == 'D' and r[j] == 'R') ans++;
            }
            if(r[0] == 'R' and r[r.size()-1] == 'D') m++;
            else if(r[0] == 'R') b++;
            else if(r[r.size()-1] == 'D') t++;
        }
        if(m){
            if(t>0 and b>0){
                t--, b--;
                ans += m+1;
                ans += min(t,b);
            }
            else if(t == 0 and b == 0) ans += m-1;
            else ans+=m;
        }
        else ans+=min(t,b);
        cout << ans << "\n";
    }
    return 0;
}