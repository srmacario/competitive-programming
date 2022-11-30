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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int cur = pos[b[i]];
        while(cur != i){
            if(abs(a[cur] - a[cur - 1]) < 2){
                cout << "-1\n";
                return 0;
            }
            swap(a[cur], a[cur - 1]);
            swap(pos[a[cur]], pos[a[cur - 1]]);
            ans.push_back(cur - 1);
            cur--;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    cout << ans.size() << "\n";
    for(auto t : ans) cout << t << " ";
    cout << "\n";
    return 0;
}