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
    ll fat[20], cnt[20];
    vector<int> f[20];
    fat[0] = 1;
    for(int i = 1; i <= 14; i++){
        cnt[i] = 0;
        fat[i] = fat[i - 1] * i;
        // cout << fat[i] << "\n";
        for(ll j = 40; j >= 0; j--){
            if((1ll << j) & fat[i]) f[i].push_back(1), cnt[i]++;
            else f[i].push_back(0);
        }
        // cout << "\n";
    }
    while(t--){
        ll n;
        int cnt_cur = 0;
        cin >> n;
        vi cur;
        for(ll j = 40; j >= 0; j--){
            if((1ll << j) & n) cur.pb(1), cnt_cur++;
            else cur.pb(0);
        }
        // db(cnt_cur);
        for(int i = 14; i >= 3; i--){
            bool ok = true;
            for(int j = 0; j < cur.size(); j++){
                if(f[i][j] and !cur[j]) ok = false;
            }
            if(ok){
                cnt_cur = cnt_cur - cnt[i] + 1;
                for(int j = 0; j < cur.size(); j++){
                    if(f[i][j]) cur[j] = 0;
                }
            }
        }
        cout << cnt_cur << "\n";
    }
    return 0;
}