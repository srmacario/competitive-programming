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

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> ans;
    for(int i = 0; i <= n; i++) ans.push_back(i);
    vector<int> edge(m + 1);
    edge[0] = 0;
    int l = 1, r = 1;
    for(int i = 1; i <= m; i++){
        cin >> edge[i];
        if(edge[i] == edge[i - 1] + 1){
            r++;
        }
        else{
            reverse(ans.begin() + l, ans.begin() + r + 1);
            l = r = edge[i];
            r++;
        }
    }
    reverse(ans.begin() + l, ans.begin() + r + 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}