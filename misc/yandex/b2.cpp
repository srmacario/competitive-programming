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
    string s, ans = "zzzz";
    cin >> s;
    for(int l=0;l<s.size()-1;l++){
        if(s[l] == s[l+1]){
            string partans;
            partans += s[l], partans += s[l+1];
            ans = min(ans,partans);
        }
        if((l+2 < s.size()) and s[l] == s[l+2]){
            string partans;
            partans += s[l], partans += s[l+1], partans += s[l+2];
            ans = min(ans,partans);
        }
    }
    cout << ((ans == "zzzz") ? "-1" : ans) << "\n";
    return 0;
}