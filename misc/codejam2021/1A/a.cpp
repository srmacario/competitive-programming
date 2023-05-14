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
    for(int k = 1; k <= t; k++){
        int n, cnt = 0;
        cin >> n;
        vector <string> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 1; i < n; i++){
            if(x[i].size() > x[i-1].size()) continue;
            if(x[i].size() == x[i-1].size()){
                if(x[i] <= x[i-1]) x[i] += "0", cnt++;
                db(x[i]);
                continue;
            }
            int cmp = 0;
            for(int j = 0; j < x[i].size(); j++){
                if(x[i][j] > x[i-1][j]){
                    cmp = 1;
                    break;
                }
                if(x[i][j] == x[i-1][j]) cmp = 0;
                if(x[i][j] < x[i-1][j]){
                    cmp = -1;
                    break;
                }
            }
            if(cmp == 1 or cmp == -1){
                while(x[i].size() < x[i-1].size()) x[i] += '0', cnt++;
                if(cmp == -1) x[i] += '0', cnt++;
            }
            if(cmp == 0){
                int sz = x[i].size();
                while(x[i].size() < x[i-1].size()){
                    x[i] += x[i-1][x[i].size()];
                    cnt++;
                }
                int co = 0;
                for(int j = x[i].size()-1; j > sz-1; j--){
                    if(x[i][j] == '9'){
                        x[i][j] = '0';
                        co = 1;
                    }
                    else{
                        x[i][j]++;
                        co = 0;
                        break;
                    }
                }
                if(co){
                    for(int j = x[i].size()-1; j > sz-1; j--) x[i][j] = '0';
                    x[i] += '0';
                    cnt++;
                }
            }
            // db(x[i]);
        }
        cout << "Case #" << k << ": " << cnt << "\n";
    }
    return 0;
}