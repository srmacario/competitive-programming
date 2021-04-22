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

int add_ext(char c, int cnt, int x, int y, int ext){
    if(ext) swap(x,y);
    int ans = 0;
    if(c == 'C'){
        if(x < 0 and y < 0) ans += y*((cnt+1)/2) + x*(cnt/2);
        if(x > 0 and y < 0) ans += y*((cnt+1)/2) + x*((cnt-1)/2);
        if(x < 0 and y > 0) ans += (x+y)*(cnt/2);
    }
    if(c == 'J'){
        if(y < 0 and x < 0) ans += x*((cnt+1)/2) + y*(cnt/2);
        if(y > 0 and x < 0) ans += x*((cnt+1)/2) + y*((cnt-1)/2);
        if(y < 0 and x > 0) ans += (x+y)*(cnt/2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int x, y, ans = 0, n, idc = 0, idj = 1;
        string s;
        cin >> x >> y >> s;
        n = (int)s.size();
        // if(c[0] > c[1]) swap(c[0], c[1]), swap(idc, idj);
        // for(int i = 0 ; i < n; i++){
        //     if(s[i] == '?') continue;
        //     if(s[i] == 'C') s[i] = idc;
        //     else s[i] = idj;
        // }
        char last = '#';
        for(int i = 0; i < n; i++){
            int cnt = 0;
            while(s[i] == '?'){
                cnt++;
                if(++i == n){
                    if(last == '#'){
                        if(x + y > 0) break;
                        if(x > 0 or y > 0) ans += min(x,y)*(cnt/2) + max(x,y)*((cnt)/2-1);
                        else ans = min(x,y)*((cnt)/2) + max(x,y)*((cnt-1)/2);
                    }
                    else ans += add_ext(last, cnt, x, y, 1);
                    break;
                }
            }
            if(i == n) break;
            if(last != s[i]){
                if(last == '#' and cnt){
                    ans += add_ext(s[i], cnt, x, y, 0);
                }
                if(last == 'C'){
                    ans += x;
                    if((cnt > 1) and (x+y) < 0) ans += (x+y)*(cnt/2);
                }
                if(last == 'J'){
                    ans += y;
                    if((cnt > 1) and (x+y) < 0) ans += (x+y)*(cnt/2);
                }
            }
            else if(last == s[i]){
                if(last == 'C'){
                    if((cnt > 0) and (x+y) < 0) ans += (x+y)*((cnt+1)/2);
                }
                if(last == 'J'){
                    if((cnt > 0) and (x+y) < 0) ans += (x+y)*((cnt+1)/2);
                }
            }
            last = s[i];
        }
        cout << "Case #" << k+1 << ": " << ans << "\n";
    }
    return 0;
}