#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

bool cmp(string a, string b){
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int c=1;c<=t;c++){
        int n;
        cin >> n;
        vector <pair<string,int>> v;
        vector <string> ini, fim;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int cnt = 0;
            string auxini, auxfim;
            for(int j=0;j<s.size();j++){
                if(s[j] == '*') break;
                auxini += s[j];
            }
            for(int j=s.size()-1;j>=0;j--){
                if(s[j] == '*') break;
                auxfim += s[j];
            }
            for(int j=0;j<s.size();j++){
                if(s[j] == '*') cnt++;
            }
            ini.pb(auxini);
            fim.pb(auxfim);
            v.pb({s,cnt});
        }
        sort(ini.begin(),ini.end(),cmp);
        sort(fim.begin(),fim.end(),cmp);
        string ansini,ansmid,ansfim;
        bool ok = true;
        for(int i=0;i<ini.size();i++){
            for(int j=i+1;j<ini.size();j++){
                for(int k=0;k<ini[i].size();k++){
                    if(ini[i][k] != ini[j][k]) ok = false;
                }
            }
        }
        for(int i=0;i<fim.size();i++){
            for(int j=i+1;j<fim.size();j++){
                for(int k=fim[i].size()-1;k>=0;k--){
                    if(fim[i][k] != fim[j][k]) ok = false;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            int cnt = 0, max = v[i].nd;
            string s = v[i].st;
            for(int j=0;j<s.size();j++){
                if(s[j] == '*') cnt++;
                else if(cnt >=1 and cnt < max) ansmid += s[j];
            }
        }
        
        if(ok){
            if(ini.size()) ansini = ini[ini.size()-1];
            if(fim.size()){
                string ransfim;
                ansfim = fim[fim.size()-1];
                for(int i=0;i<ansfim.size();i++){
                    ransfim += ansfim[ansfim.size() - 1 - i];
                }
                ansfim = ransfim;
            }
        }
        cout << "Case #" << c << ": " << (ok ? ansini + ansmid + ansfim : "*") << "\n";
    }
    return 0;
}