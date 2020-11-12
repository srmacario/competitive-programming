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
const int N = 19;
const int M = 1e6;

ll sum = 0;
ll adj[N][N], caps[N], exist[N];
map <char,int> id;
pair <int, int> ans = {0,0};

bool cns(char c){
    if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'w' or c == 'y') return false;
    return true;
}

void identify(){
    int cnt = 0;
    for(int i=0;i<26;i++){
        char c = 'a' + i;
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'w' or c == 'y') continue;
        id[c] = cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);
    string s;
    cin >> s;
    int up = 1;
    for(int i=1;i<=N;i++) up *= 2;
    identify();
    for(int i=0;i<s.size();i++){
        if(!cns(s[i])) continue;
        exist[id[s[i]]]++;
        if(i < s.size() - 1){
            if(cns(s[i+1])){
                adj[id[s[i]]][id[s[i+1]]]++;
            }
        }
        if(i){
            if(cns(s[i-1])){
                adj[id[s[i]]][id[s[i-1]]]++;
            }
        }
    }
    for(int i=0;i<up;i++){
        sum = 0;
        for(int j=0;j<N;j++) {
            caps[j] = 0;
            if((1<<j) & i) caps[j]++;
        }
        for(int j=0;j<N;j++) {
            if(!exist[j]) continue;
            for(int k = j+1;k<N;k++){
                if(!exist[k]) continue;
                if(caps[j] != caps[k]) sum += adj[j][k];
            }
        }
        if(sum > ans.st){
            ans.st = sum;
            ans.nd = i;
        }
    }
    for(int j=0;j<N;j++) {
        caps[j] = 0;
        if((1<<j) & ans.nd) caps[j]++;
    }
    for(int j=0;j<s.size();j++){
        int dif = s[j] - 'a';
        if(cns(s[j])){                
            s[j] = s[j] - caps[id[s[j]]]*32;
        }
    }
    cout << s << "\n";
    return 0;
}