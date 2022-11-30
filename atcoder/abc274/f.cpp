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
const int N = 2e3 + 5;

int n, A;
int w[N], x[N], v[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> A;
    for(int i = 0; i < n; i++) cin >> w[i] >> x[i] >> v[i];
    ll tot = 0;
    for(int i = 0; i < n; i++){
        //{time, {pos, type}}
        vector<pair<ld, pii>> events;
        ll sum = w[i];
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(v[i] == v[j]){
                if(x[j] - x[i] <= A and x[j] - x[i] >= 0) sum += w[j];
            }
            else{
                ld tin, tout;
                if(x[i] <= x[j]){
                    if(v[i] > v[j]){
                        tout = (ld)(x[i] - x[j]) / (ld)(v[j] - v[i]);
                        events.push_back({tout, {1, j}});
                        if(x[j] <= x[i] + A) sum += w[j];
                        else{
                            tin = (ld)(x[i] - x[j] + A) / (ld)(v[j] - v[i]);
                            events.push_back({tin, {0, j}});
                        }
                    }
                    else{
                        if(x[j] <= x[i] + A){
                            sum += w[j];
                            tout = (ld)(x[i] - x[j] + A) / (ld)(v[j] - v[i]);
                            events.push_back({tout, {1, j}});
                        }
                    }
                }
                else{
                    if(v[i] > v[j]) continue;
                    tin = (ld)(x[i] - x[j]) / (ld)(v[j] - v[i]);
                    tout = (ld)(x[i] - x[j] + A) / (ld)(v[j] - v[i]);
                    events.push_back({tin, {0, j}});
                    events.push_back({tout, {1, j}});
                }
            }
        }
        sort(events.begin(), events.end());
        ll ans = sum;
        // db(sum);
        for(auto e : events){
            // db(i _ e.st _ e.nd.st _ e.nd.nd);
            if(e.nd.st){
                sum -= w[e.nd.nd];
            }
            else{
                sum += w[e.nd.nd];
            }
            ans = max(sum, ans);
            // db(sum);
        }
        // db(ans);
        tot = max(ans, tot);
    }
    cout << tot << "\n";
    return 0;
}