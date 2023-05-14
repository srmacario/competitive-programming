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
const int N = 1e5+5;

int dfa[26][N];
//dfa[c][j] is the longest prefix from [0...j] which is suffix of [0...j-1]+c

void prekmp(string &p){
    int n = p.size();
    //initialize first character
    dfa[p[0]-'a'][0] = 1;
    for(int l = 0, j = 1; j <= n; j++){
        //l is last column for conflict cases
        //conflict cases will be the same since we can only match one letter
        //copy conflict cases
        for(int c = 0; c < 26; c++){
            dfa[c][j] = dfa[c][l];
        }
        if(j == n) break;
        //increment letter that matches  
        dfa[p[j]-'a'][j] = j+1;
        //conflict cases now are first column that s[j] fails
        l = dfa[p[j]-'a'][l];
    }
}

void kmp(string &s, string &p){
    int n = p.size();
    int m = s.size();
    for(int i=0, j=0; i<m ; i++){
        j = dfa[s[i]-'a'][j];
        if(j == n) db(i _ j);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //s = text
    //p = pattern
    string s,p;
    cin >> s >> p;
    prekmp(p);
    kmp(s,p);
    return 0;
}