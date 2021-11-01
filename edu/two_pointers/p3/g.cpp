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

int n;
ll c, suma, sumb, rude, ans;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c >> s;
    for(ll l = 0, r = 0; r < n; r++){
        if(s[r] == 'a') suma++;
        if(s[r] == 'b') sumb++, rude += suma;
        while(rude > c){
            if(s[l] == 'a') suma--, rude -= sumb;
            if(s[l] == 'b') sumb--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}