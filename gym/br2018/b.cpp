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

ll l[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll sum = 0, half = 0, dist = 0, cnt = 0;
    set <ll> psums;
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        sum += l[i];
        if(i != n) psums.insert(sum);
    }
    psums.insert(0);
    if(sum&1){
        cout << "N\n";
        return 0;
    }
    half = sum;
    half >>= 1;
    for(int i = 1; i <= n; i++){
        dist += l[i];
        if(psums.count((half + dist)%(sum))) cnt++;
    }
    if(cnt >= 4) cout << "Y\n";
    else cout << "N\n";
    return 0;
}