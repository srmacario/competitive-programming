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
const int N = 1e6+5, M = 40;

string ini, cur;
int n, ans;
vector<string> cs;

bool test(int sz, string &s){
    int ps[40] = {0}, rep = 0;
    for(int i = 0; i<=sz;i++){
        ps[s[i] - 'a']++;
        if(ps[s[i] -'a'] == 2) rep++;
    }
    if(rep){
        for(int l=1;l<s.size();l++){
            int r=l+sz;
            if(r >= s.size()) break;
            ps[s[l-1] - 'a']--;
            if(ps[s[l-1] - 'a'] == 1) rep--;
            ps[s[r] - 'a']++;
            if(ps[s[r] - 'a'] == 2) rep++;
            if(!rep){
                return true;
            }
        }
    }
    else{
        return true;
    }
    return false;
}

int busca(string &s){
    int l = 0, r = s.size()-1;
    while(l < r){
        int m = (l+r+1)/2;
        if(test(m,s)) l = m;
        else r = m-1;
    }
    return ++l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> ini;
    for(int i=0;i<ini.size();i++){
        if(ini[i] - 'a' >= 0) cur += ini[i];
        else{
            if(cur.size()) cs.pb(cur), cur.clear();
        }
    }
    if(cur.size()) cs.pb(cur), cur.clear();
    for(int i=0;i<cs.size();i++){
        ans = max(ans, busca(cs[i]));
    }
    cout << ans << "\n";
    return 0;
}