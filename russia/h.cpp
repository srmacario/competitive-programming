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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct parabola{
    int a, b, c;
    
    parabola(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc){}

    ld calc(ld x, ld y){
        return y - a * x * x - b * x - c;
    }

    ld get_y(ld x){
        return a * x * x + b * x + c;
    }
};
vector<parabola> par[2];

ld f(ld x, int ave){
    int id[2];
    pair<ld, int> mn, mx;
    //0 - parabola down - get min
    //1 - parabola up - get max
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < par[k].size(); i++){
            if(!k){
                if(!i) mn = {par[k][i].get_y(x), i};
                else mn = min(mn, {par[k][i].get_y(x), i});
            }
            else{
                if(!i) mx = {par[k][i].get_y(x), i};
                else mx = max(mx, {par[k][i].get_y(x), i});
            }
        }
    }
    ld y;
    if(ave) y = (mn.st + mn.st) / 2;
    else y = mn.st - mx.st;
    return y;
}

pair<double, double> ternary_search(double l, double r, int No = 200){
    //for(int i = 0; i < No; i++){
    while(r - l > EPS){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        // if (f(m1) > f(m2))
        if (f(m1, 0) < f(m2, 0))
            l = m1;
        else
            r = m2;
    }
    return {l, f(l, 1)};  
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        parabola p;
        cin >> p.a >> p.b >> p.c;
        if(p.a < 0) par[0].push_back(p);
        else par[1].push_back(p);
    }
    //parabola intersections implicitly:
    // for parabola down get min from all of them
    // for parabola up get max from all of them
    pair<ld, ld> ans = ternary_search(-LINF, LINF);
    cout << setprecision(15) << fixed << ans.st << " " << ans.nd << "\n";
    return 0;
}