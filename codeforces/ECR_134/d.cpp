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
        vector<vector<int>> a[35], b[35];
        a[30].push_back(vector<int> (n)), b[30].push_back(vector<int> (n));
        for(int i = 0; i < n; i++) cin >> a[30][0][i];
        for(int i = 0; i < n; i++) cin >> b[30][0][i];

        for(int i = 30; i > 0; i--){
            vector<vector<int>> add_a, add_b;
            bool ok = true;
            for(int j = 0; j < (int) a[i].size(); j++){
                vector<int> cur_a[2], cur_b[2];
                int cnt_a = 0, cnt_b = 0;
                for(int k = 0; k < (int) a[i][j].size(); k++){
                    if((1 << (i - 1)) & a[i][j][k]) cur_a[1].push_back(a[i][j][k]), cnt_a++;
                    else cur_a[0].push_back(a[i][j][k]);
                }
                
                for(int k = 0; k < (int) b[i][j].size(); k++){
                    if((1 << (i - 1)) & b[i][j][k]) cur_b[1].push_back(b[i][j][k]);
                    else cur_b[0].push_back(b[i][j][k]), cnt_b++;
                }

                if(cnt_a == cnt_b){
                    if(cur_a[0].size()) add_a.push_back(cur_a[0]), add_b.push_back(cur_b[1]);
                    if(cur_a[1].size()) add_a.push_back(cur_a[1]), add_b.push_back(cur_b[0]);
                }
                else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                a[i - 1] = add_a;
                b[i - 1] = add_b;
            }
            else{
                for(int j = 0; j < (int) a[i].size(); j++) a[i - 1].push_back(a[i][j]), b[i - 1].push_back(b[i][j]);
            }
        }
        int ans = -1;
        for(int i = 0; i < (int) a[0].size(); i++){
            for(int j = 0; j < (int) a[0][i].size(); j++){
                if(ans == -1) ans = (a[0][i][j] ^ b[0][i][j]);
                else ans &= (a[0][i][j] ^ b[0][i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}