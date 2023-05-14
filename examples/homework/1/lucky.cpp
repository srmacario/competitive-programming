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
const int N = 1e2+5;

string s1,s2,v;

int dfa[26][N], len1, len2;
int m[N][N][N], f[N][N][N]; 
//dfa[c][j] is the longest prefix from [0...j] which is suffix of [0...j-1]+c

void prekmp(string &p){
    int n = p.size();
    //initialize first character
    dfa[p[0]-'A'][0] = 1;
    for(int l = 0, j = 1; j <= n; j++){
        //l is last column for conflict cases
        //conflict cases will be the same since we can only match one letter
        //copy conflict cases
        for(int c = 0; c < 26; c++){
            dfa[c][j] = dfa[c][l];
        }
        if(j == n) break;
        //increment letter that matches  
        dfa[p[j]-'A'][j] = j+1;
        //conflict cases now are first column that s[j] fails
        l = dfa[p[j]-'A'][l];
    }
}

void lcs () {
    //same lcs
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            for(int k=0;k<v.size();k++){
                if (s1[i-1] == s2[j-1]){
                    int prox = dfa[s1[i-1]-'A'][k];
                    if(prox != v.size()){
                        m[i][j][prox] = max(m[i][j][prox], 1 + m[i-1][j-1][k]);
                    }
                }
                m[i][j][k] = max({m[i-1][j][k],m[i][j-1][k],m[i][j][k]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2 >> v;
    len1 = s1.size();
    len2 = s2.size();
    prekmp(v);
    lcs();
    pii best = {0,0};
    for(int k=0;k<v.size();k++){
        best = max({best,{m[len1][len2][k],k}});
    }
    if(!best.st){
        cout  << "0\n";
        return 0;
    }
    string ans;
    int i = len1, j = len2, pos = best.nd;
    while(i > 0 and j > 0){
        if(m[i-1][j][pos] == m[i][j][pos]) i--;
        else{
            if(m[i][j-1][pos] == m[i][j][pos]) j--;
            else{
                for(int nxt=0;nxt < v.size();nxt++){
                    if(dfa[s1[i-1]-'A'][nxt] == pos and m[i][j][pos] == m[i-1][j-1][nxt]+1){
                        pos = nxt;
                        break;
                    }
                }
                ans += s1[i-1];
                i--,j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;
}