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
const int N =21e5+5;

int n, m, cur, cnt;
vector<pii> cant_heal;
vi heal;

bool cmp(pii a, pii b){
    if(a.nd == b.nd) return a.st < b.st;
    return b.nd < a.nd;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cnt = 0;
        heal.clear(), cant_heal.clear();
        cin >> n >> m;
        cur = m;
        for(int i = 0; i < n; i++){
            int t, h;
            cin >> t >> h;
            h = min(m, h);
            if(t <= h) heal.pb(h - t);
            else cant_heal.pb({t, h});
        }
        sort(heal.begin(), heal.end(), greater<int>());
        sort(cant_heal.begin(), cant_heal.end(), cmp);
        for(int i = 0; i < cant_heal.size(); i++){
            // db(cur _ cant_heal[i].st);
            if(cur >= cant_heal[i].st){
                cur += cant_heal[i].nd - cant_heal[i].st;
                cnt++;
            }
            else{
                int tmp = cant_heal[i].st - cur;
                cur = 0;
                while(tmp and !heal.empty()){
                    // db(cur _ tmp);
                    if(tmp <= heal[(int)heal.size() - 1]){
                        heal[(int)heal.size()-1] -= tmp;
                        cur = cant_heal[i].nd + heal[(int)heal.size()-1];
                        tmp = 0;
                        cnt++;
                    }
                    else{
                        tmp -= heal[(int)heal.size() - 1];
                    }
                    cnt++;
                    heal.pop_back();
                }
            }
        }
        cnt += (int)heal.size();
        // db(cnt _ n);
        cout << (cnt == n ? "YES" : "NO") << "\n";
    }
    return 0;
}