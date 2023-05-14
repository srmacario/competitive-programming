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
        int n, m;
        cin >> n >> m;
        vector<piii> pts(m);
        vector<piii> old(m);
        for(int i = 0; i < m; i++){
            cin >> pts[i].st >> pts[i].nd.st;
            old[i] = pts[i];
            pts[i].nd.nd = i;
        }
        sort(pts.begin(), pts.end());
        priority_queue<pii> pq;

        ll sum = 0;
        for(int i = 0; i < 2 * n; i++){
            pq.push({pts[i].nd.st, pts[i].nd.nd});
            sum = sum + pts[i].nd.st;
        }
        for(int i = 2*n; i < m; i++){
            pii nxt = pq.top();
            if(pts[i].nd.st < nxt.st){
                pq.pop();
                pq.push({pts[i].nd.st, pts[i].nd.nd});
                sum = sum - nxt.st + pts[i].nd.st;
            }
        }
        cout << sum << "\n";
        vector<pii> ans;
        for(int i = 0; i < n; i++){
            ans.pb({old[pq.top().nd].st, pq.top().nd + 1});
            pq.pop();
            ans.pb({old[pq.top().nd].st, pq.top().nd + 1});
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < n; i++){
            // db(pts[ans[i].nd - 1].st _ pts[ans[2 * n - i - 1].nd - 1].st);
            cout << ans[i].nd << " " << ans[2 * n - i - 1].nd << "\n";
        }
    }
    return 0;
}