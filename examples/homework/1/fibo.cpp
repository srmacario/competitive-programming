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
const int INF = 0x3f3f3f3f, MOD = 1e9+9;
const int N = 1e5+5;

int dfa[26][N], cnt, nxt[3][N];
ll occ[3][N];
//dfa[c][j] is the longest prefix from [0...j] which is suffix of [0...j-1]+c

void prekmp(string &p){
    int n = p.size();
    //initialize first character
    dfa[p[0]-'a'][0] = 1;
    for(int l = 0, j = 1; j <= n; j++){
        //l is last column for conflict cases
        //conflict cases will be the same since we can only match one letter
        //copy conflict cases
        for(int c = 0; c < 26; c++) dfa[c][j] = dfa[c][l];
        if(j == n) break;
        //increment letter that matches  
        dfa[p[j]-'a'][j] = j+1;
        //conflict cases now are first column that s[j] fails
        l = dfa[p[j]-'a'][l];
    }
}

void kmp(string &s, string &p, int id){
    int n = p.size();
    int m = s.size();
    for(int j=0;j<=n;j++){
        cnt = 0;
        int k = j;
        for(int i=0; i < m; i++){
            k = dfa[s[i]-'a'][k];
            if(k == n) cnt++;
        }
        nxt[id][j] = k;
        occ[id][j] = cnt;
    }
}

void merge(string &p, int id){
    int n = p.size();
    for(int i=0;i<=n;i++){
        nxt[id][i] = nxt[(id+2)%3][nxt[(id+1)%3][i]];
        occ[id][i] = (occ[(id+1)%3][i] + occ[(id+2)%3][nxt[(id+1)%3][i]])%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    string p, s1 = "a", s2 = "b";
    cin >> p >> k;
    prekmp(p);
    kmp(s1,p,1), kmp(s2,p,2);
    for(int i=3;i<=k;i++){
        merge(p,i%3);
    }
    cout << occ[k%3][0] << "\n";
    return 0;
}