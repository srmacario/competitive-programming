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
const int N = 4e5+5;

multiset<string> str;
string s[N], t[N];
int h, w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> s[i];
    for(int i = 0; i < h; i++) cin >> t[i];
    for(int j = 0; j < w; j++){
        string tmp;
        for(int i = 0; i < h; i++){
            tmp += t[i][j];
        }
        str.insert(tmp);
    }
    bool ok = true;
    for(int j = 0; j < w; j++){
        string tmp;
        for(int i = 0; i < h; i++){
            tmp += s[i][j];
        }
        if(str.count(tmp)){
            str.erase(str.lower_bound(tmp));
        }
        else{
            ok = false;
        }
    }
    
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}