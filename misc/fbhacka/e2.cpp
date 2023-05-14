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
const int N = 55;

string dict[234300], a, b;
int dp[N][N], n, m;

int calc(int n, int m){
    if(~dp[n][m]) return dp[n][m];
    if(n == 0 or m == 0) return dp[n][m] = max(n,m);
    if(a[n-1] == b[m-1]) return dp[n][m] = calc(n-1,m-1);
    return dp[n][m] = 1 + min({calc(n-1,m),calc(n,m-1),calc(n-1,m-1)});
}

int main(){
    int dictCnt=0, t;
    ifstream dataFile;
    string str, word, amount;
    dataFile.open("dictionary.tsv");
    while(!dataFile.eof()) {
        getline( dataFile, str);
        stringstream buffer(str);
        buffer >> word >> amount;
        dict[dictCnt++] = word;
    }
    cin >> t;
    while(t--){
        cin >> a;
        vector<string> saida;
        for(int i = 0; i<234300; i++){
            memset(dp,-1,sizeof(dp));
            b = dict[i];
            n = a.size(), m = b.size();
            int ans = calc(n,m);
            if(ans and ans<=2) saida.pb(b); 
        }
        if(saida.size()){
            sort(saida.begin(), saida.end());
            for(auto x : saida) cout << x << " ";
        }
        cout << "\n";
    }

}