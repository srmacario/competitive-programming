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
const int N = 5e5+5;

string cur;

void intos(ll x){
    while(x){
        cur += (x%10) + '0';
        x/=10;
    }
    reverse(cur.begin(), cur.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    intos(n);
    //decrease
    for(int i = 9; i >= 0; i--){
        bool ok = true;
        string ans;
        ans += cur[0];
        for(int j = 1; j < (int)cur.size(); j++){
            if(ans.back() - i < '0'){
                ok = false;
                break;
            }
            ans += ans.back() - i;
        }
        if(ok){
            if(ans >= cur){
                cout << ans << "\n";
                return 0;
            }
        }
    }
    //increase
    for(int i = 0; i < 10; i++){
        bool ok = true;
        string ans;
        ans += cur[0];
        for(int j = 1; j < (int)cur.size(); j++){
            if(ans.back() + i > '9'){
                ok = false;
                break;
            }
            ans += ans.back() + i;
        }
        if(ok){
            if(ans >= cur){
                cout << ans << "\n";
                return 0;
            }
        }
    }
    //decrease + 1
    for(int i = 9; i >= 0; i--){
        bool ok = true;
        string ans;
        if(cur[0] < '9') ans += cur[0] + 1;
        else ans += "10";
        for(int j = 1; j < (int)cur.size(); j++){
            if(ans.back() - i < '0'){
                ok = false;
                break;
            }
            ans += ans.back() - i;
        }
        if(ok){
            cout << ans << "\n";
            return 0;
        }
    }
    return 0;
}