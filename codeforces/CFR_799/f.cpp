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

int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        bool ok = false;
        cin >> n;
        int cnt[10] = {0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= 10;
            cnt[a[i]]++;
        }
        for(int i = 0; i <= 9; i++){
            if(!cnt[i]) continue;
            cnt[i]--;
            for(int j = 0; j <= 9; j++){
                if(!cnt[j]) continue;
                cnt[j]--;
                for(int k = 0; k <= 9; k++){
                    if(!cnt[k]) continue;
                    if((i + j + k )%10 == 3) ok = true;
                }
                cnt[j]++;
            }
            cnt[i]++;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}