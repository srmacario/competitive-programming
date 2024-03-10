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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k, enter[N], in_queue[N];
queue<int> q[N];
int last_time = 1;
vector<int> sad;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int t = 1;
    for(int i = 0; i < 2 * n; i++){
        int op, p, f;
        cin >> op;
        if(op == 1){
            cin >> p >> f;
            enter[t] = p;
            q[f].push(t);
            in_queue[p] = 1;
            t++;
        }
        else{
            cin >> f;
            int cur = q[f].front(); q[f].pop();
            for(int j = last_time; j < cur; j++){
                if(in_queue[enter[j]]) sad.push_back(enter[j]);
            }
            last_time = max(last_time, cur + 1);
            in_queue[enter[cur]] = 0;
        }
    }
    sort(sad.begin(), sad.end());
    cout << sad.size() << "\n";
    for(auto s : sad) cout << s << " ";
    cout << "\n";
    return 0;
}