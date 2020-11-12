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

string p;
int b[N], n, m;

void prekmp(){
    b[0] = -1;
    for(int i=0, j = -1; i < m; b[++i] = ++j)
        while(j >=0 and p[i] != p[j])
            j = b[j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string x,y;
    while(t--){
        int p1 = 0, p2 = 0;
        cin >> x >> y;
        p = x + y;
        m = p.size();
        prekmp();
        p1 = b[p.size()-1];
        p = y + x;
        m = p.size();
        prekmp();
        p2 = b[p.size()-1];
        
    }
    return 0;
}