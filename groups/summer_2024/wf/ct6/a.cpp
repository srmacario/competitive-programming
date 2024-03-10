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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s.size() == 1){
            ans = s[i] - '0' + 1;
            break;
        }
        if(i) ans += 10;
        else{
            //expected right
            string expec;
            for(int j = i + 1; j < s.size(); j++) expec += s[i];
            if(expec.empty()) expec += "0";
            int nexpec = stoi(expec);

            //current right
            string cur = (i == s.size() - 1 ? "0" : s.substr(i + 1, s.size() - i - 1));
            int ncur = stoi(cur);
            ans += s[i] - '0' + (i != 0) - 1;
            // db(ncur _ nexpec);
            // db(ncur _ nexpec);
            if(ncur >= nexpec){
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}