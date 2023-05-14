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
const int N = 1e5 + 5;

int n[4], a[4][N], l[4], ans = INF, resp[4];

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%d", &n[i]);
        for(int j = 0; j < n[i]; j++) scanf("%d", &a[i][j]);
        sort(a[i], a[i] + n[i]);
        a[i][n[i]] = INF;
    }
    for(int i = 0; i < N; i++){
        int tmp = 0;
        for(int j = 0; j < 4; j++){
            while(l[j] < n[j] and (a[j][l[j]] < i)) l[j]++;
            tmp = max(tmp, abs(a[j][l[j]] - i));
        }
        if(ans > tmp){
            ans = tmp;
            for(int j = 0; j < 4; j++){
                resp[j] = a[j][l[j]];
            }
        }
    }
    for(int j = 0; j < 4; j++){
        printf("%d ", resp[j]);
    }
    printf("\n");
    return 0;
}