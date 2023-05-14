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

pii p[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        p[i] = {a,b};
    }
    for(int i=n;i>=0;i--){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i>=p[j].st and i<=p[j].nd) cnt++;
        }
        if(i == cnt){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}