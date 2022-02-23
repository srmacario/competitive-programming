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
const int N = 2e6+10; // Upper limit to n

int cmp[N], ans[N], pr[N];
vector<int> fat[N];

void primes() {
    for(int i = 2; i < N; i++) ans[i] = 1;
    for (int i = 2; i < N; i++) {
        if (!cmp[i]) {
            for (int j = i; j < N; j += i){
                cmp[j] = 1;
                int tmp = j, qtd = 0;
                while(!(tmp % i)){
                    qtd++;
                    tmp /= i;
                }
                ans[j] *= (qtd + 1);
                pr[j]++;
            }
        }
    }
}


int main(){
    primes();
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x] - pr[x]);
    }
    return 0;
}