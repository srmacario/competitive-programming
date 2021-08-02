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

int mk[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    priority_queue <int> mono;
    priority_queue <pii> poly;
    int cnt = 1;
    for(int i=1;i<=q;i++){
        int op, m;
        cin >> op;
        if(op == 1){
            cin >> m;
            mono.push(-cnt);
            poly.push({m,-cnt});
            cnt++;
        }
        if(op == 2){
            while(true){
                int cur = -mono.top();
                mono.pop();
                if(!mk[cur]){
                    mk[cur]++;
                    cout << cur << " ";
                    break;
                }
                else continue;
            }
        }
        if(op == 3){
            while(true){
                pii cur = poly.top();
                poly.pop();
                if(!mk[-cur.nd]){
                    mk[-cur.nd]++;
                    cout << -cur.nd << " ";
                    break;
                }
                else continue;
            }
        }
    }
    return 0;
}