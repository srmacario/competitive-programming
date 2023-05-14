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
        cin >> n;
        vector<int> a(n);
        vector<int> ans;
        int mx = -INF, mn = INF, dif = 0;
        priority_queue<int> pq;
        multiset<int> ms;
        int zero = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
            if(a[i] > 0) pq.push(a[i]);
            if(a[i] < 0) ms.insert(-a[i]);
            if(a[i] == 0) zero++;
        }
        dif = mx - mn;
        if(mx >= dif){
            cout << "No\n";
            continue;
        }
        int cur_sum = 0;
        bool ok = true;
        while(!pq.empty()){
            int cur = pq.top();
            pq.pop();
            cur_sum += cur;
            if(cur_sum < dif){
                ans.push_back(cur);
                continue;
            }
            int lft = cur_sum - dif;
            while(ms.size() and lft >= 0){
                auto it = ms.upper_bound(lft);
                if(it == ms.end()) it--;
                lft -= *it;
                cur_sum -= *it;
                ans.push_back(-(*it));
                ms.erase(it);
            }
            if(cur_sum < 0) cur_sum = 0;
            ans.push_back(cur);
            if(!ms.size() and lft >= 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << "No\n";
            continue;
        }
        for(auto u : ms) ans.push_back(-u);
        for(int i = 0; i < zero; i++) ans.push_back(0);
        cout << "Yes\n";
        for(auto r : ans) cout << r << " ";
        cout << "\n";
    }
    return 0;
}