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

const ld EPS = 1e-7, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    vector<pair<string,pii>> now, ans;
    cin >> s;
    for(int l=0;l<s.size()-1;l++){
        if(s[l] == s[l+1]){
            string partans;
            partans += s[l], partans += s[l+1];
            ans.pb({partans,{l,l+1}});
            now.pb({partans,{l,l+1}});
        }
        if(l+2 < s.size()){
            if(s[l] == s[l+2]){
                string partans;
                partans += s[l], partans += s[l+1], partans += s[l+2];
                ans.pb({partans,{l,l+2}});
                now.pb({partans,{l,l+2}});
            }
        }
    }
    while(!now.empty()){
        pair<string,pii> u = now.back();
        now.pop_back();
        if(u.nd.st == 0 or u.nd.nd == s.size() - 1) continue;
        else{
            if(s[u.nd.st - 1] == s[u.nd.nd + 1]){
                string partans;
                partans += s[u.nd.st - 1], partans += u.st, partans += s[u.nd.nd + 1];
                ans.pb({partans,{u.nd.st - 1,u.nd.nd + 1}});
                now.pb({partans,{u.nd.st - 1,u.nd.nd + 1}});
            }
        }
    }
    if(ans.empty()){
        cout << "-1\n";
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout << ans[0].st << "\n";
    return 0;
}