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

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    cin >> n >> x;
    vector<pll> v(n), a(n);
    string ans;
    for(int i = 0; i < n; i++){
        cin >> v[i].st;
        a[i] = {v[i].st, i};
        ans.push_back('0');
    }
    for(int i = 0; i < n; i++){
        cin >> v[i].nd;
    }
    sort(a.begin(), a.end());
    ll cur = 0;
    set<pll> inside, outside, diff_inside;
    for(int i = 0; i < n; i++){
        if(cur + a[i].st <= x){
            cur += a[i].st;
            inside.insert(a[i]);
            diff_inside.insert({v[a[i].nd].nd - v[a[i].nd].st, a[i].nd});
            ans[a[i].nd] = '1';
        }
        else{
            outside.insert({v[a[i].nd].nd, a[i].nd});
        }
    }
    while(diff_inside.size() or outside.size()){
        ll d_inside = LINF, d_outside = LINF;
        //try insert from outside
        if(diff_inside.empty()){
            if(inside.empty()) break;
            pll out = *outside.begin(), ins = *inside.rbegin();
            d_outside = out.st - ins.st;
            if(cur + d_outside <= x){
                ans[out.nd] = '2';
                ans[ins.nd] = '0';
                cur += d_outside;
                inside.erase(ins);
                outside.erase(out);
            }
            else break;
        }
        //try insert from inside
        else if(outside.empty()){
            pll diff_ins = *diff_inside.begin(); 
            d_inside = diff_ins.st;
            if(cur + d_inside <= x){
                ans[diff_ins.nd] = '2';
                cur += d_inside;
                inside.erase({v[diff_ins.nd].st, diff_ins.nd});
                diff_inside.erase(diff_ins);
            }
            else break;
        }
        //try from both
        else{
            pll out = *outside.begin(), ins = *inside.rbegin(), diff_ins = *diff_inside.begin();
            d_outside = out.st - ins.st;
            d_inside = diff_ins.st;
            if(d_inside <= d_outside){
                if(cur + d_inside <= x){
                    ans[diff_ins.nd] = '2';
                    cur += d_inside;
                    inside.erase({v[diff_ins.nd].st, diff_ins.nd});
                    diff_inside.erase(diff_ins);
                }
                else break;
            }
            else{
                if(cur + d_outside <= x){
                    ans[out.nd] = '2';
                    ans[ins.nd] = '0';
                    cur += d_outside;
                    inside.erase(ins);
                    diff_inside.erase({v[ins.nd].nd - v[ins.nd].st, ins.nd});
                    outside.erase(out);
                }
                else break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}