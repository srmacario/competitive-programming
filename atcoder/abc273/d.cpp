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

map<int, vector<int>> row, col;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, n, q;
    pii pos;
    cin >> h >> w >> pos.st >> pos.nd >> n;
    for(int i = 0; i < n; i++){
        pii x;
        cin >> x.st >> x.nd;
        row[x.st].push_back(x.nd);
        col[x.nd].push_back(x.st);
    }
    for(auto &v : row) sort(v.nd.begin(), v.nd.end());
    for(auto &v : col) sort(v.nd.begin(), v.nd.end());

    cin >> q;
    for(int i = 0; i < q; i++){
        char d;
        int l;
        cin >> d >> l;
        if(d == 'L'){
            if(row.count(pos.st)){
                auto it = lower_bound(row[pos.st].begin(), row[pos.st].end(), pos.nd);
                if(it != row[pos.st].begin()){
                    it--;
                    int wall = *it;
                    if(wall > pos.nd){
                        pos.nd = max(pos.nd - l, 1);
                    }
                    else{
                        pos.nd = max(pos.nd - l, wall + 1);
                    }
                }
                else{
                    pos.nd = max(pos.nd - l, 1);
                }
            }
            else{
                pos.nd = max(pos.nd - l, 1);
            }
        }
        if(d == 'R'){
            if(row.count(pos.st)){
                auto it = upper_bound(row[pos.st].begin(), row[pos.st].end(), pos.nd);
                if(it != row[pos.st].end()){
                    int wall = *it;
                    pos.nd = min(pos.nd + l, wall - 1);
                }
                else{
                    pos.nd = min(pos.nd + l, w);
                }
            }
            else{
                pos.nd = min(pos.nd + l, w);
            }
            
        }
        if(d == 'U'){
            if(col.count(pos.nd)){
                auto it = lower_bound(col[pos.nd].begin(), col[pos.nd].end(), pos.st);
                if(it != col[pos.nd].begin()){
                    it--;
                    int wall = *it;
                    if(wall > pos.st){
                        pos.st = max(pos.st - l, 1);
                    }
                    else{
                        pos.st = max(pos.st - l, wall + 1);
                    }
                }
                else{
                    pos.st = max(pos.st - l, 1);
                }
            }
            else{
                pos.st = max(pos.st - l, 1);
            }
            
        }
        if(d == 'D'){
            if(col.count(pos.nd)){
                auto it = upper_bound(col[pos.nd].begin(), col[pos.nd].end(), pos.st);
                if(it != col[pos.nd].end()){
                    int wall = *it;
                    pos.st = min(pos.st + l, wall - 1);
                }
                else{
                    pos.st = min(pos.st + l, h);
                }
            }
            else{
                pos.st = min(pos.st + l, h);
            }
            
        }
        cout << pos.st << " " << pos.nd << "\n";
    }
    return 0;
}