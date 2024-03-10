#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
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
    int n;
    cin >> n;
    vector<string> names(n);
    vector<pii> points(n);
    for(int i = 0; i < n; i++){
        cin >> names[i];
        points[i].nd = -i;
        cin >> points[i].st;
        points[i].st *= 10;
        int mn = INF, mx = -INF;
        for(int j = 0; j < 6; j++){
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
            points[i].st += x;
        }
        points[i].st -= mn + mx;
    }
    vector<pii> ans;
    sort(points.begin(), points.end(), greater<pii>());
    ans.push_back(points[0]);
    for(int i = 1; i < min(1000, n); i++){
        if(points[i].st == ans.back().st) ans.push_back(points[i]);
        else if(ans.size() <= 2) ans.push_back(points[i]);
    }
    for(auto a : ans){
        cout << names[-a.nd] << " " << a.st << "\n";
    }
    return 0;
}