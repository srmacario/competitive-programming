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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 1;
        priority_queue<ll> need, current;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            need.push(x);
            sum += x;
        }
        current.push(sum);
        bool ok = true;
        while(cnt < n){
            ll x = current.top();
            current.pop();
            // db(x _ need.top());
            //atual é menor do que o que eu preciso
            if(x < need.top()){
                ok = false;
                break;
            }
            //atual é maior, preciso dividir
            if(x != need.top()){
                if(x >= 2){
                    ll u = x / 2, v = (x + 1) / 2;
                    current.push(u);
                    current.push(v);
                }
            }
            if(x == need.top()){
                need.pop();
                cnt--;
            }
            cnt++;
        }
        while(current.size()){
            // db(current.top() _ need.top());
            if(current.top() == need.top()) current.pop(), need.pop();
            else{
                ok = false;
                break;
            }
        }
        if(current.size() or need.size()) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}