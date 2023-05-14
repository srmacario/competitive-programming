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

string p;
vector<string> pat;
int n;

bool dfs(string &s, int pos_p, int pos_s){
    if(pos_p == pat.size()){
        if(pos_s != s.size()){
            if(p[p.size() - 1] == '*') return true;
            return false;
        }
        return true;
    }
    for(int i = pos_s; i <= s.size() - pat[pos_p].size(); i++){
        if(s.substr(i, pat[pos_p].size()) == pat[pos_p]){
            bool nxt = dfs(s, pos_p + 1, i + pat[pos_p].size());
            if(nxt) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> n;
    string cur;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '*'){
            if(cur.size()){
                pat.push_back(cur);
                cur.clear();
            }
            continue;
        }
        cur.push_back(p[i]);
    }
    if(cur.size()){
        pat.push_back(cur);
        cur.clear();
    }
    vector<string> ans;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(!pat.size()){
            ans.push_back(s);
            continue;
        }
        bool ok = false;
        for(int pos_s = 0; pos_s < s.size(); pos_s++){
            int cur = pos_s, pos_p = 0;
            for(; pos_p < (int)pat.size() - 1; pos_p++){
                bool matched = false;
                for(int k = cur; k < s.size() - pat[pos_p].size(); k++){
                    if(s.substr(k, pat[pos_p].size()) == pat[pos_p]){
                        cur = k + pat[pos_p].size();
                        matched = true;
                        break;
                    }
                }
                if(!matched) break;
            }
            if(pos_p < (int)pat.size() - 1) continue;
            if(p[p.size() - 1] == '*'){
                for(int k = cur; k < s.size() - pat[pos_p].size(); k++){
                    if(s.substr(k, pat[pos_p].size()) == pat[pos_p]){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            else{
                if(s.substr(s.size() - pat[pos_p].size(), pat[pos_p].size()) == pat[pos_p]){
                    ok = true;
                    break;
                }
            }
        }
        if(ok) ans.push_back(s);
    }
    for(auto a : ans) cout << a << "\n";
    return 0;
}