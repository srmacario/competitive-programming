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

int p[N], q[N], t[N];
pii ind[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> p[i];
        ind[p[i]].st = i;
    }
    for(int i=0;i<n;i++){
        cin >> q[i];
        ind[q[i]].nd = i;
    }
    int ans = 1;
    for(int i=0;i<=ind[p[0]].nd;i++) t[i] = ans;
    for(int i=1;i<n;i++){
        if(ind[p[i]].st < ind[p[i-1]].nd){
            for(int j=ind[p[i-1]].nd; j<= ind[p[i]].nd; j++) t[i] = ans;
        }

    }
    return 0;
}