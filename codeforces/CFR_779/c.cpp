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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi c(n + 5);
        vector<int> pos;
        for(int i = 1; i <= n; i++){
            cin >> c[i];
            if(c[i] == 1) pos.push_back(i);
        }
        if(pos.empty()){
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int cnt = 2;
        for(int i = pos[0] + 1; i <= n; i++){
            if(c[i] > cnt) ok = false;
            cnt++;
        }
        int look = 2;
        cnt = 1;
        // db(ok);
        for(int i = pos[0] - 1; i >= 1; i--){
            if(c[i] == look){
                pos.push_back(i);
            }
            else{
                if(c[i] > n - pos.size()) ok = false;
            }
            n--;
        }
        cnt = pos.size();
        for(int i = pos.back() + 1; i <= n; i++){
            if(i == pos.back()) pos.pop_back();
            else{
                
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}