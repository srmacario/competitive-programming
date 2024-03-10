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
const int N = 2e5+5;

int r[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        r[c % 5]++;
    }
    int mn;
    ans = r[0] + min(r[1], r[4]) + min(r[2], r[3]);
    for(int i = 1; i <= 2; i++){
        mn = min(r[i], r[5 - i]);
        r[i] -= mn, r[5 - i] -= mn;
    }
    vector<pii> pending;
    for(int i = 1; i <= 4; i++){
        if(!r[i]) continue;
        pending.push_back({i, r[i]});
    }
    sort(pending.begin(), pending.end());
    if(pending.size() == 1){
        ans += pending.back().nd / 5;
    }
    else if(pending.size() == 2){
        if(pending[0].st == 1){
            if(pending[1].st == 2){
                mn = min(pending[0].nd, pending[1].nd/2);
                pending[0].nd -= mn, pending[1].nd -= 2*mn;
                ans += mn;

                mn = min(pending[0].nd/3, pending[1].nd);
                pending[0].nd -= 3*mn, pending[1].nd -= mn;
                ans += mn;
                ans += pending[0].nd/5 + pending[1].nd/5;
            }
            else{
                mn = min(pending[0].nd/2, pending[1].nd);
                pending[0].nd -= 2*mn, pending[1].nd -= mn;
                ans += mn;

                mn = min(pending[0].nd, pending[1].nd/3);
                pending[0].nd -= mn, pending[1].nd -= 3*mn;
                ans += mn;
                ans += pending[0].nd/5 + pending[1].nd/5;
            }
        }
        else{
            if(pending[0].st == 2){
                mn = min(pending[0].nd, pending[1].nd/2);
                pending[0].nd -= mn, pending[1].nd -= 2*mn;
                ans += mn;

                mn = min(pending[0].nd/3, pending[1].nd);
                pending[0].nd -= 3*mn, pending[1].nd -= mn;
                ans += mn;
                ans += pending[0].nd/5 + pending[1].nd/5;
            }
            else{
                mn = min(pending[0].nd/2, pending[1].nd);
                pending[0].nd -= 2*mn, pending[1].nd -= mn;
                ans += mn;

                mn = min(pending[0].nd, pending[1].nd/3);
                pending[0].nd -= mn, pending[1].nd -= 3*mn;
                ans += mn;
                ans += pending[0].nd/5 + pending[1].nd/5;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}