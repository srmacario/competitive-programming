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

int lvl[N];
map <string, int> m;

int ord(char c){
    if(c >= 'a' and c <= 'z') return 2*(c-'a')+1;
    else return 2*(c-'A');
}

bool cmp(string a, string b){
    string x, y;
    for(int i = 0; i < a.size(); i++) x += ord(a[i]);
    for(int i = 0; i < b.size(); i++) y += ord(b[i]);
    return x < y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vi num, den, lvl;
    lvl.pb(0), num.pb(0), den.pb(1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            lvl.pb(num.back()), num.pb(num.back()), den.pb(num.back()^1);
            continue;
        }
        if(s[i] == ')'){
            lvl.pop_back(), num.pop_back(), den.pop_back();
            continue;
        }
        if(s[i] == '*'){
            if(s[i+1] == '('){
                lvl.pb(num.back()), num.pb(num.back()), den.pb(num.back()^1);
                i++;
                continue;
            }
            lvl.back() = num.back();
            continue;
        }
        if(s[i] == '/'){
            if(s[i+1] == '('){
                lvl.pb(den.back()), num.pb(den.back()), den.pb(num.back()^1);
                i++;
                continue;
            }
            lvl.back() = den.back();
            continue;
        }
        string val;
        while(s[i] != '*' and s[i] != '/' and s[i] != '(' and s[i] != ')'){
            val += s[i++];
            if(i == s.size()) break;
        }
        if(lvl.back()) m[val]--;
        else m[val]++;
        i--;
    }
    vector <string> ans[2];
    for(auto x : m){
        if(x.nd > 0){
            for(int i = 0; i < abs(x.nd); i++) ans[0].pb(x.st);
        }
        if(x.nd < 0){
            for(int i = 0; i < abs(x.nd); i++) ans[1].pb(x.st);
        }
    }
    for(int i = 0; i < 2; i++){
        sort(ans[i].begin(), ans[i].end(), cmp);
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];
            if(j == ans[i].size()-1) cout << "\n";
            else cout << "*";
        }
        if(!ans[i].size()) cout << "1\n";
    }
    return 0;
}