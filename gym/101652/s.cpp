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

piii calc(string& s){
    int max_now = 0;
    piii max_all = {0, {0, 0}};
    for(int l = 0, r = 0; r < s.size(); r++){
        int num = 1;
        if(s[r] == 'R') num = -1;
        max_now += num;
        if(max_now < 0){
            piii p = {-1, {-r, -r}};
            max_all = max(max_all, p);
            l = r + 1;
            max_now = 0;
        }
        else{
            piii p = {max_now, {-l, -r}};
            max_all = max(max_all, p);
        }
    }
    return max_all;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    piii ans = calc(s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R') s[i] = 'B';
        else s[i] = 'R';
    }
    ans = max(ans, calc(s));
    cout << -ans.nd.st + 1 << " " << -ans.nd.nd + 1 << "\n";
    return 0;
}

//BB RRBRRB RB