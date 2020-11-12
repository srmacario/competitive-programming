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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string w;
        for(int i=0;i<s.size();i++) w+= "1";
        int x;
        cin >> x;
        bool ok = true;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                if(i+1 > x) {
                    w[i-x] = '0';
                }
                if(i+1+x <= s.size()) {
                    w[i+x] = '0';
                }
            }
        }
        for(int i=0;i<w.size();i++){
            int cnt[2] = {0};
            if(i+1 > x) {
                cnt[w[i - x]-'0']++;
            }
            if(i+1+x <= s.size()) {
                cnt[w[i + x]-'0']++;
            }
            if(s[i] == '1'){
                if(!cnt[1]) ok = false;
            }
            else{
                if(cnt[1]) ok = false;
            }
        }
        cout << (ok ? w : "-1") << "\n";
    }
    return 0;
}