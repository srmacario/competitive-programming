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
const int N = 505;

int A[N][N], id[N];
vi ans[N];

void print(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vi clean(vi v, int n){
    sort(v.begin(), v.end());
    vi out;
    v.pb(n);
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] == v[i+1]) i++;
        else out.pb(v[i]);
    }
    return out;
}

bool gauss(int n, int m){
    for(int j = 0; j < m; j++) { //collumn to eliminate
        int l = j;
        for(int i = j+1; i < n; i++) //find largest pivot
            if(A[i][j] > A[l][j])
                l = i;
        if(!A[l][j]) return false;
        if(l != j){
            for(int k = 0; k < m+1; k++) { //Swap lines
                swap(A[l][k],A[j][k]);
            }
            vi tmp = ans[l];
            ans[l] = ans[j];
            ans[j] = tmp;
        }
        for(int i = 0; i < n; i++) { //eliminate column
            if(i == j) continue;
            if(A[i][j]){
                for(int k = j; k < m; k++){
                    A[i][k] ^= A[j][k];
                }
                for(auto op : ans[j]) ans[i].pb(op);
                ans[i] = clean(ans[i], n);
            }
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        id[i] = i;
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
        ans[i].pb(i);
    }
    if(gauss(n,n)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < ans[i].size(); j++){
                printf("%d ", ans[i][j]+1);
            }
            printf("\n");
        }
    }
    else printf("-1\n");
    return 0;
}