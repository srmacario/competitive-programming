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
const int N = 105;

int a[N];

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, ans = 0;
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]);
        }
        for(int j = 0; j < n-1; j++){
            pii mn = {a[j], j};
            for(int k = j; k < n; k++){
                mn = min(mn, {a[k], k});
            }
            ans += mn.nd - j + 1;
            reverse(a + j, a + mn.nd + 1);
        }
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}