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

int n;
vector<int> p[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    p[0].resize(n + 1);
    p[0][0] = n + 1;
    for(int i = 1; i <= n; i++) cin >> p[0][i];
    vector<pii> ans;
    while(true){
        //move first
        ans.push_back({1, 3});
        p[2].push_back(p[0].back());
        p[0].pop_back();
        
        //pile to third rod while in decreasing order
        while(p[2].back() > p[0].back()){
            ans.push_back({1, 3});
            p[2].push_back(p[0].back());
            p[0].pop_back();
        }
        //check if solution is ready
        if(p[2].size() == n) break;

        //move next not decreasing to mid rod
        ans.push_back({1, 2});
        p[1].push_back(p[0].back());
        p[0].pop_back();

        //reorder in rod 1
        while(p[2].size() and p[1].back() > p[2].back()){
            ans.push_back({3, 1});
            p[0].push_back(p[2].back());
            p[2].pop_back();
        }

        //insert ring from mid rod
        ans.push_back({2, 1});
        p[0].push_back(p[1].back());
        p[1].pop_back();

        //continue from right rod
        while(p[2].size()){
            ans.push_back({3, 1});
            p[0].push_back(p[2].back());
            p[2].pop_back();
        }
    }
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a.st << " " << a.nd << "\n";
    return 0;
}