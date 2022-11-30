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

int bit[32][N];
int pref;

bool cmp(pii a, pii b){
    for(int i = 30; i >= 0; i--){
        if(bit[i][a.nd] and !bit[i][b.nd]) return true;
        if(!bit[i][a.nd] and bit[i][b.nd]) return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pref = 0;
        vector<pii> a(n);
        vector<int> ans, used(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].st;
            a[i].nd = i;
        }
        sort(a.begin(), a.end());
        ans.push_back(a[n - 1].st), used[a[n - 1].nd] = 1;
        pref = ans[0];
        while(true){
            for(int i = 0; i < n; i++){
                for(int j = 30; j >= 0; j--){
                    int cur_bit = (pref & (1 << j));
                    int tmp_bit = (a[i].st & (1 << j));
                    if(!cur_bit and tmp_bit) bit[j][a[i].nd] = 1;
                    else bit[j][a[i].nd] = 0;
                }
            }
            sort(a.begin(), a.end(), cmp);
            bool ok = false;
            for(int i = 30; i >= 0; i--){
                if(bit[i][a[0].nd] == 1){
                    ok = true;
                    break;
                }
            }
            if(ok){
                pref |= a[0].st;
                ans.push_back(a[0].st);
                used[a[0].nd] = 1;
            }
            else{
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(!used[a[i].nd]) ans.push_back(a[i].st);
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}