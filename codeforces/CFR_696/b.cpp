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

const int N = 1e6+10;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    primes();
    while(t--){
        int d;
        scanf("%d",&d);
        int num1, num2;
        int ini = 0;
        for(int i=0;i<pr.size();i++){
            if(pr[i] - 1 >= d){
                num1 = pr[i];
                ini = i+1;
                break;
            }
        }
        for(int i=ini;i<pr.size();i++){
            if(pr[i] - num1 >= d){
                num2 = pr[i];
                break;
            }
        }
        printf("%d\n",num1*num2);
    }
    return 0;
}