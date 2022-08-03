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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 3e5+5;

string pre;
int n;
ll ans[N]; 

string dfs(int pos, int h){
    //pos + 1
    //dif = n - h -> 2 ^ (n - h)
    if(n == h){
        ans[pos] = 1;
        string x = {pre[pos - 1]};
        return x;
    }
    int l = 2 * pos, r = 2 * pos + 1;
    string a = dfs(l, h + 1);
    string b = dfs(r, h + 1);
    ans[pos] = ((ans[l] * ans[r]) % MOD);
    if(a != b) ans[pos] = (ans[pos] + ((ans[l] * ans[r]) % MOD)) %MOD;
    if(a < b) swap(a, b);
    return pre[pos - 1] + a + b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> pre;
    // ord(1, 1);
    dfs(1, 1);
    cout << ans[1] << "\n";
    return 0;
}

/*
    BAAAAAAAABBABAB
    BAAAAAAAABBABBA
    BAAAAAAAABABBAB
    BAAAAAAAABABBBA
    BABBABABAAAAAAA
    BABBABBAAAAAAAA
    BABABBABAAAAAAA
    BABABBBAAAAAAAA
    
*/