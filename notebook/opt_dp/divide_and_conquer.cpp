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

int n;

// cost function
ll C(ll i, ll j) {return 0;}
//dp vectors
vector <ll> dp_bef(n), dp_cur(n);

//iterate compute over k, in the end, shift cur to bef and clear cur

void compute(int l, int r, int optl, int optr){
    // stop condition  
    if(l > r) return;
    int mid = (l+r)/2;
    //best : cost, pos
    pair<ll,ll> best = {INF,-1};

    //searchs best, lower bound to right, upper bound to left
    for(int k = optl; k <= min(mid, optr); k++){
        best = min(best, {dp_bef[k] + C(k,mid), k});
    }
    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid-1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}