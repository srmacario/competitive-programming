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
        vector<vector<int>> c(n + 5);
        for(int i = 0; i < n; i++){
            int cur;
            cin >> cur;
            c[cur].push_back(i);
        }
        for(int i = 1; i <= n; i++){
            int maxsofar = 0, maxnow = 0, top = -1;
            if(c[i].size()) maxsofar = maxnow = 1, top = c[i][0];
            for(int j = 1; j < c[i].size(); j++){
                if((c[i][j] - top) % 2){
                    maxnow++;
                    top = c[i][j];
                }
                maxsofar = max(maxsofar, maxnow);
            }
            cout << maxsofar << " ";
        }
        cout << "\n";
    }
    return 0;
}