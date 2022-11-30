//https://codeforces.com/gym/102644/problem/A
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

typedef long double type;

struct matrix{
    //matrix n x m
    vector<vector<type>> a;
    int n, m;
    matrix() = default;

    matrix(int _n, int _m) : n(_n), m(_m){
        a.resize(n, vector<type>(m));
    }

    matrix operator *(matrix other){
        matrix result(this->n, other.m);
        for(int i = 0; i < result.n; i++){
            for(int j = 0; j < result.m; j++){
                for(int k = 0; k < this->m; k++){
                    result.a[i][j] = (result.a[i][j] + a[i][k] * other.a[k][j]);
                    //result.a[i][j] = (result.a[i][j] + (a[i][k] * other.a[k][j]) % MOD) % MOD;
                }
            }
        }
        return result;
    }
};

matrix identity(int n){
    matrix id(n, n);
    for(int i = 0; i < n; i++) id.a[i][i] = 1;
    return id;
}

matrix fexp(matrix b, ll e){
    matrix ans = identity(b.n);
    while(e){
        if(e & 1) ans = (ans * b);
        b = b * b;
        e >>= 1;
    }
    return ans;
}

int n;
ld p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    matrix dp(2, 2);
    dp.a = {{1 - p, p}, {p, 1 - p}};
    matrix ans = fexp(dp, n);
    cout << setprecision(15) << fixed << ans.a[0][0] << "\n";
    return 0;
}