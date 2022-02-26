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
const int N = 2e3+5;

int l[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }
    ll ans = 0;
    l[n] = INF;
    sort(l, l  + n + 1);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            //condição da desigualdade diminui os testes
            //basta testar a condição: c < a + b, visto que o array está ordenado  
            for(int k = j + 1; l[k] < l[i] + l[j]; k++){
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}