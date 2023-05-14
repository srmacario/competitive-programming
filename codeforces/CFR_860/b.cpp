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

int t, m, n[N], win[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        map<int, int> cnt, a;
        cin >> m;
        vector<vector<int>> day;
        day.push_back({});
        for(int i = 1; i <= m; i++){
            cin >> n[i];
            day.push_back(vector<int>(n[i]));
            for(int j = 0; j < n[i]; j++){
                cin >> day[i][j];
                cnt[day[i][j]]++;
                if(cnt[day[i][j]] > 1) a[day[i][j]] = i;
            }
        }
        bool ok = true;
        set<int> cant;
        for(auto p : a){
            win[p.nd] = p.st;
            cant.insert(p.st);
        }
        for(int i = 1; i <= m; i++){
            if(win[i]) continue;
            for(int j = 0; j < n[i]; j++){
                if(!cant.count(day[i][j])){
                    cant.insert(day[i][j]);
                    win[i] = day[i][j];
                }
            }
            if(win[i] == 0){
                ok = false;
                break;
            }
        }
        if(!ok) cout << "-1\n";
        else{
            for(int i = 1; i <= m; i++) cout << win[i] << ' ';
            cout << "\n";
        }
        for(int i = 1; i <= m; i++) win[i] = 0;
    }
    return 0;
}