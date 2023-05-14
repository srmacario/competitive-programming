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
const int N = 1e5+5, M = 2e6+5;

int a[N], freq[M], n, mx;
vi resp;

bool dfs(int pos, int cur){
    resp.pb(a[pos]);
    if(cur == n){
        printf("YES\n");
        return true;
    }
    bool ans = false;
    for(int i=pos-1;i>=0;i--){
        if(freq[a[i]] > 0){
            freq[a[i]]--;
            if(freq[a[pos] - a[i]] > 0){
                freq[a[pos] - a[i]]--;
                ans = dfs(i, cur+1);
                freq[a[pos] - a[i]]++;
                if(ans){
                    freq[a[i]]++;
                    return true;
                }
            }
            freq[a[i]]++;
            resp.pop_back();
            return false;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        mx = 0;
        scanf("%d",&n);
        for(int i=0;i<2*n;i++){
            scanf("%d",&a[i]);
            mx = max(mx,a[i]);
            freq[a[i]]++;
        }
        sort(a,a+2*n);
        bool ok;
        vector<pii> ans;
        for(int i=2*n-2;i>=0;i--){
            freq[a[i]]--, freq[mx]--;
            ans.pb({mx,a[i]});
            ok = dfs(2*n-1,1);
            if(ok){
                int last = mx;
                for(int i=1;i<n;i++){
                    freq[resp[i]]--, freq[last-resp[i]]--;
                    ans.pb({resp[i],last - resp[i]});
                    last = resp[i];
                }
                printf("%d\n",ans[0].st + ans[0].nd);
                for(int i=0;i<ans.size();i++) printf("%d %d\n", ans[i].st, ans[i].nd);
                break;
            }
            ans.pop_back();
            freq[a[i]]++, freq[mx]++;
        }
        if(!ok) printf("NO\n");
        for(int i=0;i<2*n;i++){
            freq[a[i]] = 0;
        }
        resp.clear();
    }
    return 0;
}