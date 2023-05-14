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

void print(int t, bool ok, int ans){
    cout << "Case #" << t << ": ";
    if(ok) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int j=1;j<=t;j++){
        int x, y;
        string s;
        cin >> x >> y >> s;
        int ans = 0;
        bool ok = false;
        if(abs(x) + abs(y) == ans){
            print(j,true,ans);
            continue;
        }
        for(int i=0;i<s.size();i++){
            ans++;
            if(s[i] == 'N') y++;
            if(s[i] == 'S') y--;
            if(s[i] == 'E') x++;
            if(s[i] == 'W') x--;
            if(abs(x) + abs(y) <= ans){
                ok = true;
                print(j,true,ans);
                break;
            }
        }
        if(!ok){
            print(j,false,ans);
            continue;
        }
    }
    return 0;
}