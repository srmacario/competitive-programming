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

map <int,int> good;
int zer, uni;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool ok = true;
    vi ans;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x < 0){
            if(good[-x]) good[-x]--;
            else if (zer) zer--, ans.pb(-x);
            else ok = false;
        }
        else if(x > 0) good[x]++;
        else zer++, uni++;
    }
    if(ok){
        cout << "Yes\n";
        while(ans.size() < uni) ans.pb(1);
        for(auto u : ans) cout << u << " ";
        cout << "\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}