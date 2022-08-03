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
const int N = 1e4+5;

int n, m, k, dp[N][15][105];
vector<int> nxt[15];
string t;

int dfa[15][N];
//dfa[c][j] is the longest prefix from [0...j] which is suffix of [0...j-1]+c

void prekmp(string &p){
    int n = p.size();
    //initialize first character
    dfa[p[0] - '0'][0] = 1;
    for(int l = 0, j = 1; j <= n; j++){
        //l is last column for conflict cases
        //conflict cases will be the same since we can only match one letter
        //copy conflict cases
        for(int c = 0; c < 10; c++){
            dfa[c][j] = dfa[c][l];
        }
        if(j == n) break;
        //increment letter that matches  
        dfa[p[j] - '0'][j] = j+1;
        //conflict cases now are first column that s[j] fails
        l = dfa[p[j] - '0'][l];
    }
}

void init(){
    //0
    nxt[0] = {4, 6};
    //1
    nxt[1] = {6, 8};
    //2
    nxt[2] = {7, 9};
    //3
    nxt[3] = {4, 8};
    //4
    nxt[4] = {0, 3, 9};
    //5
    nxt[5] = {};
    //6
    nxt[6] = {0, 1, 7};
    //7
    nxt[7] = {2, 6};
    //8
    nxt[8] = {1, 3};
    //9
    nxt[9] = {2, 4};

    memset(dp, -1, sizeof(dp));
}

//dp[i][j] != string with size i left, starting with num
int calc(int sz, int num, int pos, string s){
    if(dp[sz][num][pos] != -1) return dp[sz][num][pos];
    if(pos == t.size()) return 0;
    if(sz == 1) return 1;
    int ans = 0;
    for(auto prox : nxt[num]){
        ans = (ans + calc(sz - 1, prox, dfa[prox][pos], s)) % MOD;
    }
    return dp[sz][num][pos] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cin >> n >> m >> k;
    if(m){
        cin >> t;
        prekmp(t);
    }
    else{
        for(int i = 0; i < 10; i++) dfa[i][0] = dfa[i][1] = 1;
    }
    int ans = 0;
    for(auto prox : nxt[k]){
        ans = (ans + calc(n, prox, dfa[prox][0], "")) % MOD;
    }
    cout << ans << "\n";
    return 0;
}