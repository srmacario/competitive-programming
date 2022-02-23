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
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<piii> ans;
        bool ok = true;
        if(a[n - 2] > a[n - 1]){
            cout << "-1\n";
            continue;
        }
        else{
            for(int i = n - 3; i >= 0; i--){
                if(a[i] <= a[i + 1]){
                    if(a[i + 1] - a[n - 1] <= a[i + 1]){
                        ans.pb({i + 1, {i + 2, n}});
                    }
                }
                else{
                    if(a[i + 1] - a[n - 1] <= a[i + 1]){
                        ans.pb({i + 1, {i + 2, n}});
                    }
                    else{
                        cout << "-1\n";
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(!ok){
            continue;
        }
        cout << ans.size() << "\n";
        for(auto a : ans) cout << a.st << " " << a.nd.st << " " << a.nd.nd << "\n";
    }
    return 0;
}