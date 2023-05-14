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
typedef unsigned long long ull;
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
const int N = 5;

int pot[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    pot[0] = 1;
    for(int i=1;i<5;i++) pot[i] = 10*pot[i-1];
    int resp = 0, tot = 0;
    for(int i=0;i<m;i++){
        int b, cur, sum = 0, best = 0;
        scanf("%d%d",&b,&cur);
        for(int i=1;i<n;i++){
            int x;
            scanf("%d",&x);
            sum += x;
        }
        if(sum + cur <= b) tot+=cur;
        for(int i=0;i<5;i++){
            sum += pot[i];
            if(sum <= b) best = pot[i];
            sum -= pot[i];
        }
        resp += best;
    }
    printf("%d\n",resp-tot);
    return 0;
}