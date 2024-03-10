#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5 + 5;

set<pll> ordered_w;
set<int> alive;
vector<pll> ans;
int n;
ll w[N], sum;
pll cur;

void change(pll chn){
    ordered_w.erase(chn);
    w[chn.nd] += w[ans.back().nd] / 2;
    ordered_w.insert({w[chn.nd], chn.nd});
    if(chn == cur){
        cur = {w[chn.nd], chn.nd};
    }
    else{
        sum -= chn.st;
        if(w[chn.nd] > cur.st){
            sum += cur.st;
            cur = {w[chn.nd], chn.nd};
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];   
        ordered_w.insert({w[i], i});
        alive.insert(i);
    }
    alive.insert(0), alive.insert(n + 1);
    cur = *ordered_w.lower_bound({(*ordered_w.rbegin()).st, 0});
    for(int i = 1; i <= n; i++)
        if((make_pair(w[i], i)) != cur) sum += w[i];
    db(sum);
    for(int i = 1; i <= n; i++) cout << w[i] << " ";
    cout << "\n";
    for(int k = 1; k < n; k++){
        if(cur.st > sum){
            ans.push_back({(*ordered_w.begin()).st, (*ordered_w.begin()).nd});
            alive.erase((*ordered_w.begin()).nd);
            sum -= (*ordered_w.begin()).st;
            ordered_w.erase(ordered_w.begin());
        }
        else{
            ans.push_back(cur);
            ordered_w.erase(cur);
            cur = *ordered_w.lower_bound({(*ordered_w.rbegin()).st, 0});
            sum -= cur.st;
            alive.erase(cur.nd);
        
        }
        auto l = (alive.lower_bound(ans.back().nd));
        db(*l);
        l--;
        pll chn = {w[*l], *l};
        change(chn);
        auto r = (alive.upper_bound(ans.back().nd));
        chn = {w[*r], *r};
        change(chn);
        db(*l _ *r _ sum);
        for(int i = 1; i <= n; i++) cout << w[i] << " ";
        cout << "\n";
    }
    for(auto a : ans) cout << a.nd << " " << a.st << "\n";
    return 0;
}