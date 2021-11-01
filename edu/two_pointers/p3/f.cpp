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

int n, m, freq[26], tmp[26];
ll ans;
string s, c;

bool check(){
    for(int i = 0; i < 26; i++){
        if(tmp[i] > freq[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> c;
    for(auto ch : c) freq[ch - 'a']++;
    for(ll l = 0, r = 0; r < n; r++){
        tmp[s[r] - 'a']++;
        while(!check()) tmp[s[l++] - 'a']--;
        ans += (r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}