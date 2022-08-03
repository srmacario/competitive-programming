#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+9;
const int N = 4e6 + 5, M = 2005;

ull p[N], h[M][M];
ull pr = 1777771;
int hp, wp, hm, wm;

void build(vector<string> &s) {
    p[0] = 1, p[1] = pr;
    for(int i = 2; i < N; i++) p[i] = p[i - 1] * p[1];
    for(int j = 0; j < s.size(); j++)
        for(int i = 1; i <= s[j].size(); i++)
            h[j][i] = ((p[1] * h[j][i - 1]) + s[j][i - 1]);
}

ull base_hash(vector<string> &s){
    ull ans = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].size(); j++){
            ans = (p[1] * ans) + s[i][j];
        }
    }
    return ans;
}

// 1-indexed
ull fhash(int pos, int l, int r) {
    return (h[pos][r] - ((h[pos][l - 1] * p[r - l + 1])));
}

ull calc_hash(int ini){
    ull ans = 0;
    for(int i = 0; i < hp; i++){
        ans = (p[wp] * ans) + fhash(i, ini, ini + wp - 1);
    }
    return ans;
}

ull change_hash(int last, int next, int ini, ull current_hash){
    current_hash = current_hash - fhash(last, ini, ini + wp - 1) * p[wp * (hp - 1)];
    current_hash = current_hash * p[wp] + fhash(next, ini, ini + wp - 1);
    return current_hash;
}

/*
    5 4 3 2 1 0
    5 4 3 2 1 0
    5 4 3 2 1 0
    5 4 3 2 1 0

    for each j:
        calc initial hash
        iterate going down
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> hp >> wp >> hm >> wm;
    vector<string> paint(hp), master(hm);
    for(int i = 0; i < hp; i++) cin >> paint[i];
    for(int i = 0; i < hm; i++) cin >> master[i];
    //build hashes
    build(master);
    ll hash_p = base_hash(paint);

    //look for masterpiece
    int count = 0;
    for(int j = 0; j + wp <= wm; j++){
        ull current_hash = calc_hash(j + 1);
        for(int i = 0; i + hp <= hm; i++){
            count += (hash_p == current_hash);
            current_hash = change_hash(i, i + hp, j + 1, current_hash);
        }
    }
    cout << count << "\n";
    return 0;
}