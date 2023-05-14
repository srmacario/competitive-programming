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
const int N = 1e5+5, M = 30;

ll memo[M][M], pot[M];

void pre(){
    pot[0] = 1;
    for(int i = 1; i <= 18; i++){
        pot[i] = 10*pot[i-1];
    }
    for(int i = 1; i <= 18; i++){
        for(int j = 1; j <= 9; j++){
            if(i == 1) memo[i][j] = 1;
            else memo[i][j] = pot[i-2];
            //db(i _ j _ memo[i][j]);
        }
    }
}

ll calc(ll n){
    ll ans = 0;
    ll aux = n, p = 0;
    int num[M] = {0};
    while(aux){
        ++p;
        num[p] = aux%10;
        //db(num[p]);
        aux /= 10;
    }
    //db(num[p]);
    for(int i = 1; i < p; i++){
        for(int j = 1; j <= 9; j++) ans += memo[i][j];
    }
    for(int j = 1; j < num[p]; j++) ans += memo[p][j];
    for(int i = p-1; i > 1; i--){
        ans += (num[i]) * pot[i-2];
    }
    if(num[p] <= num[1] and num[p] > 0) ans++;
    //db(num[p] _ p _ ans); 
    return ans;
}

int main(){
    ll a, b;
    scanf("%lld%lld", &a, &b);
    pre();
    printf("%lld\n", calc(b) - calc(a-1));
    return 0;
}