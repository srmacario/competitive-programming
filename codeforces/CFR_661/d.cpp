#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vii ok;
        vi last[2], ans(n);
        for(int i=0;i<n;i++){
            int cur = s[i] - '0';
            if(!last[cur^1].size()){
                vi aux;
                aux.pb(i);
                ok.pb(aux);
                last[cur].pb(ok.size()-1);
            }
            else{
                int pos = last[cur^1].back();
                ok[pos].pb(i);
                last[cur^1].pop_back();
                last[cur].pb(pos);
            }
        }
        cout << ok.size() << "\n";
        for(int i=0;i<ok.size();i++){
            for(int j=0;j<ok[i].size();j++){
                ans[ok[i][j]] = i+1;
            }
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}