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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> freq;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }
        piii ans = {0, {0, 0}};
        int l = freq.begin() -> st, r = freq.begin() -> st;
        int next = l;
        for(auto it = freq.begin(); it != freq.end(); it++){
            r = it -> st;
            if(it -> nd < k or it -> st != next){
                auto dum = it;
                if(it -> nd < k){
                    ++dum;
                    if(dum == freq.end()) break;
                }
                l = dum -> st;
                next = l;
            }
            next++;
            piii cur = {r - l, {l, r}};
            ans = max(ans, cur);
        }
        if(ans.nd.st == 0) cout << "-1\n";
        else cout << ans.nd.st << " " << ans.nd.nd << "\n";
    }
    return 0;
}