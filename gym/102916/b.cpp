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
const int N = 2e5+5;

pll op1[N], op2[N];
    int n;

bool check(ld m){
    ld num = 0, den = 0;
    for(int i = 0; i < n; i++){
        ld left = (ld)op1[i].nd - op1[i].st*m, right = (ld)op2[i].nd - op2[i].st*m;
        if(left +EPS > right){
            num += op1[i].nd;
            den += op1[i].st;
        }
        else{
            num += op2[i].nd;
            den += op2[i].st;
        }
    }
    if(num/den + EPS > m) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ld ansnum = 0, ansden = 0;
    for(int i = 0; i < n; i++){
        cin >> op1[i].st >> op1[i].nd;
        cin >> op2[i].st >> op2[i].nd;
    }
    ld l = 0, r = 1e9;
    while(r - l > EPS){
        ld m = (l + r)/2;
        if(check(m)) l = m;
        else r = m;
    }
    cout << setprecision(12) << fixed << l << "\n";
    return 0;
}