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
const int INF = 0x3f3f3f3f, MOD = 1e9;
const int N = 1e5+5;

int main(){
    set<ll> s;
    int n;
    scanf("%d", &n);
    ll last = 0;
    for(int i = 0; i < n; i++){
        char op;
        int x;
        scanf(" %c %d", &op, &x);
        if(op == '+'){
            if(last){
                s.insert((x+last+MOD)%MOD);
                last = 0;
            }
            else{
                s.insert(x);
            }
        }
        else{
            auto ans = s.lower_bound(x);
            if(ans != s.end()){
                printf("%lld\n", *ans);
                last = *ans;
            }
            else printf("-1\n"), last = -1;
        }
    }
    return 0;
}