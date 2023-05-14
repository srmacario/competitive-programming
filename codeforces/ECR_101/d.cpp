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
        int cur = n;
        vi mk(n+5);
        vector<pii> v1, v2;
        mk = {0};
        mk[n] = 1;
        while(cur > 3){
            for(int i=2;i<=cur;i++){
                if(i*i == cur){
                    mk[i]++;
                    cur /= i;
                    v2.pb({n,i});
                    if(i!=2) v2.pb({i,n});
                    break;
                }
                else if(i*i > cur){
                    mk[i-1]++;
                    cur = (cur-1)/(i-1)+1;
                    v2.pb({n,i-1});
                    if(i!=3) v2.pb({i-1,n});
                    break;
                }
            }
        }
        if(cur == 3){
            mk[2]++;
            v2.pb({n,2});
            cur = (cur-1)/2+1;
        }
        if (cur == 2){
            mk[2]++;
            v2.pb({n,2});
        }
        for(int i=2;i<=n;i++){
            if(!mk[i]) v1.pb({i,i+1});
        }
        cout << v1.size() + v2.size() << "\n";
        for(int i=0;i<v1.size();i++) cout << v1[i].st << " " << v1[i].nd << "\n";
        for(int i=0;i<v2.size();i++) cout << v2[i].st << " " << v2[i].nd << "\n";
    }
    return 0;
}