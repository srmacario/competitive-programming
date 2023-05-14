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

int n, sum;
priority_queue<pii> coin;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        sum += x;
        if(x) coin.push({x, i});
    }
    if(sum % 2){
        cout << "no\n";
    }
    else{
        if(!coin.empty() and coin.top().st > sum / 2){
            cout << "no\n";
            return 0; 
        }
        vector<pii> ans;
        while(!coin.empty()){
            pii t1 = coin.top();
            coin.pop();
            pii t2 = coin.top();
            coin.pop();
            ans.push_back({t1.nd, t2.nd});
            t1.st--, t2.st--;
            if(t1.st) coin.push(t1);
            if(t2.st) coin.push(t2);
        }
        cout << "yes\n";
        for(auto a : ans) cout << a.st << " " << a.nd << "\n";
    }
    return 0;
}