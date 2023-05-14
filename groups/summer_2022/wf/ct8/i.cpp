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

ld f(ld r_sup, ld r_down, ld m1, ld x1, ld x2, ld a, ld up, ld down){
    ld y1 = 0, y2;
    //y_sup
    //cout << r_sup << " " << m1 << " " << x1 << "\n";
    ld cte = r_sup * r_sup - (m1 - x1) * (m1 - x1);
    //cout << cte << "\n";
    if(up == 1) y1 = a - sqrt(cte);
    else y1 = a + sqrt(cte);
    //y_down
    //cout << r_down << " " << m1 << " " << x2 << "\n";
    cte = r_down * r_down - (m1 - x2) * (m1 - x2);
    if(down == 1) y2 = -sqrt(cte);
    else y2 = sqrt(cte);
    //cout << cte << "\n";
    //cout << y1 << " " << y2 << "\n";
    return fabs(y1 - y2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    while(true){
        cin >> a;
        if(a == -1) return 0;
        vector<int> r[2], dir[2];
        //x, dir, idx
        vector<pair<int, pair<int, int>>> sweep;
        for(int i = 0; i < 2; i++){
            int x = 0;
            int c;
            char d;
            cin >> c >> d;
            r[i].resize(c);
            dir[i].resize(c);
            if(d == 'N') dir[i][0] = 0;
            else dir[i][0] = 1;
            for(int j = 0; j < c; j++){
                cin >> r[i][j];
                sweep.push_back({x, {j, i}});
                x += 2*r[i][j];
                if(j) dir[i][j] = dir[i][j - 1] ^ 1;
            }
        }
        sort(sweep.begin(), sweep.end());
        pair<int, pair<int, int>> cur_nor = {-1, {-1, -1}}, cur_sou = {-1, {-1, -1}};
        ld ans = a;
        for(auto s : sweep){
            if(s.nd.nd) cur_sou = s;
            else cur_nor = s;
            if(cur_nor.st == -1 or cur_sou.st == -1) continue;
            if(dir[cur_nor.nd.nd][cur_nor.nd.st] == 1 and dir[cur_sou.nd.nd][cur_sou.nd.st] == 0){
                int r_sup = r[cur_nor.nd.nd][cur_nor.nd.st];
                int r_down = r[cur_sou.nd.nd][cur_sou.nd.st];
                ld x_l = s.st, x_r = min(cur_nor.st + 2*r_sup, cur_sou.st + 2*r_down);
                while(x_r - x_l > EPS){
                    ld fm1, fm2;
                    ld m1 = x_l + (x_r - x_l) / 3;
                    ld m2 = x_r - (x_r - x_l) / 3;
                    fm1 = f(r_sup, r_down, m1, cur_nor.st + r_sup, cur_sou.st + r_down, a, dir[cur_nor.nd.nd][cur_nor.nd.st], dir[cur_sou.nd.nd][cur_sou.nd.st]);
                    fm2 = f(r_sup, r_down, m2, cur_nor.st + r_sup, cur_sou.st + r_down, a, dir[cur_nor.nd.nd][cur_nor.nd.st], dir[cur_sou.nd.nd][cur_sou.nd.st]);
                    if (fm1 > fm2)
                        x_l = m1;
                    else
                        x_r = m2;
                }
                ld fm1 = f(r_sup, r_down, x_l, cur_nor.st + r_sup, cur_sou.st + r_down, a, dir[cur_nor.nd.nd][cur_nor.nd.st], dir[cur_sou.nd.nd][cur_sou.nd.st]);
                ans = min(ans, fm1);
            }
        }
        cout << setprecision(2) << fixed << ans << "\n";
    }
    return 0;
}