#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e3 + 5;

int dp[N][N], k, t, x,  vis[N][N];
string s;

int calc(int p, int q){
    if(q > k)
        return -1e9;
    if(p + 2 >= s.size())
        return 0;
    if(vis[p][q] == x)
        return dp[p][q];
    vis[p][q] = x;
    dp[p][q] = calc(p + 1, q);
    int h[30] = {0}, hh = 0, p1 = -1, p2 = -1, p3 = -1;
    if(p)
        p1 = s[p - 1] - 'a';
    if(p + 3 < s.size())
        p2 = s[p + 3] - 'a';
    h[s[p] - 'a']++;
    h[s[p + 1] - 'a']++;
    h[s[p + 2] - 'a']++;
    for(int i = 0; i < 30; i++)
        if(i != p1 && i != p2)
            hh = max(hh, h[i]);
    dp[p][q] = max(dp[p][q], 3 + calc(p + 3, q + 3 - hh));
    if(p + 3 < s.size()){
        h[s[p + 3] - 'a']++;
        if(s[p + 1] == s[p + 2])
            p3 = s[p + 1] - 'a';
        hh = 0;
        p2 = -1;
        if(p + 4 < s.size())
            p2 = s[p + 4] - 'a';
        for(int i = 0; i < 30; i++)
            if(i != p1 && i != p2 && i != p3)
                hh = max(hh, h[i]);
        dp[p][q] = max(dp[p][q], 4 + calc(p + 4, q + 4 - hh));
    }
    if(p + 4 < s.size()){
        h[s[p + 4] - 'a']++;
        hh = 0;
        p2 = -1;
        p3 = s[p + 2] - 'a';
        if(p + 5 < s.size())
            p2 = s[p + 5] - 'a';
        for(int i = 0; i < 30; i++)
            if(i != p1 && i != p2 && i != p3)
                hh = max(hh, h[i]);
        dp[p][q] = max(dp[p][q], 5 + calc(p + 5, q + 5 - hh));
    }
    return dp[p][q];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        x++;
        cin >> s >> k;
        cout << calc(0, 0) << '\n';
    }
    return 0;
}