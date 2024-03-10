#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

int n;
vector<int> files[2];
ld tax, w[2] = {(ld)1 / (ld)4, (ld)3 / (ld)4}, downloaded[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> tax;
    for(int i = 0; i < n; i++){
        char op;
        int sz;
        cin >> op >> sz;
        files[op == 'P'].push_back(sz);
    }
    for(int k = 0; k < 2; k++){
        sort(files[k].begin(), files[k].end(), greater<int>());
        if(files[k].empty()) w[k ^ 1] = 1;
    }
    ld total = 0;
    while(files[0].size() or files[1].size()){
        ld faster = LINF;
        for(int k = 0; k < 2; k++){
            if(files[k].size()){
                faster = min(faster, (((ld)files[k].back() - downloaded[k])/((tax * w[k]) / (ld)files[k].size())));
            }
        }
        total += faster;
        for(int k = 0; k < 2; k++){
            if(files[k].empty()) continue;
            ld cur_tax = ((tax * w[k]) / (ld)files[k].size());
            int last_size = files[k].back();
            ld missing_time = (((ld)files[k].back() - downloaded[k])/((tax * w[k]) / (ld)files[k].size()));
            if(eq(missing_time, faster)){
                while(files[k].size() and files[k].back() == last_size){
                    files[k].pop_back();
                }
            }
            downloaded[k] += faster * cur_tax;
        }
        for(int k = 0; k < 2; k++){
            if(files[k].empty()) w[k ^ 1] = 1;
        }
    }
    cout << setprecision(20) << fixed << total << "\n";
    return 0;
}