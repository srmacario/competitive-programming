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

int buc[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            buc[x%m]++;
        }
        int cnt = 0;
        if(buc[0]) cnt++;
        for(int i = 1; i <= m/2; i++){
            if(i == m/2 and (m/2) == (m+1)/2){
                if(buc[i]) cnt++;
                continue;
            }
            if(buc[i] or buc[m-i]){
                int dif = abs(buc[i] - buc[m-i]);
                if(dif <= 1) cnt++;
                else cnt += dif;
            }
        }
        for(int i = 0; i < m; i++) buc[i] = 0;
        cout << cnt << "\n";
    }
    return 0;
}