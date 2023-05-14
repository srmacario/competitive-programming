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
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        vector<vector<ll>> block;
        vector<ll> freq(12);
        block.push_back(freq);
        block.back()[s[0][1] - 'a']++;
        for(int i = 1; i < n; i++){
            if(s[i][0] != s[i - 1][0]){
                block.push_back(freq);
            }
            block.back()[s[i][1] - 'a']++;
        }
        ll ans = 0;
        
        for(auto b : block){
            for(int i = 0; i < 12; i++){
                freq[i] += b[i];
                // cout << b[i] << " ";
                ans -= ((b[i] - 1) * b[i]) / 2;
                for(int j = i + 1; j < 12; j++){
                    ans += 1ll * b[i] * b[j];
                }
            }
            // cout << "\n";
        }
        for(int i = 0; i < 12; i++) ans += ((freq[i] - 1) * freq[i]) / 2;
        cout << ans << "\n";
    }
    return 0;
}