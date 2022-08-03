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
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        for(auto c : s){
            if(c == '1') cnt++;
        }
        if(cnt % 2 or cnt == 0){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                pos = (i + 1)%n;
                rotate(s.begin(), s.begin() + i + 1, s.end());
                break;
            }
        }
        bool ini = true;
        for(int i = 1; i < s.size(); i++){
            if(ini){
                cout << (i + pos)%n + 1 << " " << (pos)%n + 1 << "\n";
                ini = false;
            }
            if(s[i] == '0'){
                cout << (i + pos)%n + 1 << " " << (i + pos + 1)%n + 1 << "\n";
            }
            else{
                ini = true;
            }
        }
    }
    return 0;
}