#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define st first
#define nd second

using ll = long long;
using ld = long double;

const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9;

ld d, v[3], t;
ld pos[3], cur;

ld ge(ld x, ld y){return x + EPS > y;}
ld le(ld x, ld y){return x - EPS < y;}
ld eq(ld x, ld y){return ge(x, y) and le(x, y);}

pair<bool, ld> fw(){
    //pos[1] = pos[2] + (v[2] - v[1]) * tmp
    ld tmp = (pos[1] - pos[2]) / (v[2] - v[1]);
    ld tmp_d = (d - pos[1]) / v[1];
    if(tmp_d > tmp){
        if(ge(cur + tmp, t)){
            return {true, pos[2] + (v[2]) * (t - cur)};
        }
        pos[0] = pos[0] + v[0] * tmp;
        pos[1] = pos[1] + v[1] * tmp;
        pos[2] = pos[2] + v[2] * tmp;
        cur += tmp;
        return {false, 0};
    }
    else{
        if(ge(cur + tmp_d, t)){
            return {true, pos[2] + (v[2]) * (t - cur)};
        }
        pos[0] = pos[0] + v[0] * tmp_d;
        pos[1] = pos[1] + v[1] * tmp_d;
        pos[2] = pos[2] + v[2] * tmp_d;
        cur += tmp_d;

        //continue 
        ld tmp = (pos[1] - pos[2]) / (v[2]);
        if(ge(cur + tmp, t)){
            return {true, pos[2] + (v[2]) * (t - cur)};
        }
        pos[0] = pos[0] + v[0] * tmp;
        pos[2] = pos[2] + v[2] * tmp;
        cur += tmp;
        return {false, 0};
    }
}

pair<bool, ld> bw(){
    //pos[0] = pos[2] - (v[0] + v[2]) * tmp
    ld tmp = (pos[0] - pos[2]) / (-v[0] - v[2]);
    if(ge(cur + tmp, t)){
        return {true, pos[2] - v[2] * (t - cur)};
    }
    pos[0] = pos[0] + v[0] * tmp;
    pos[1] = min(d, pos[1] + v[1] * tmp);
    pos[2] = pos[2] - v[2] * tmp;
    cur += tmp;
    return {false, 0};
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> d >> v[0] >> v[1] >> v[2] >> t;
    pos[0] = 0, pos[1] = 1, pos[2] = 0;
    if(ge(t, d / v[0])){
        cout << setprecision(15) << fixed << d << "\n";
        return 0;
    }
    while(true){
        pair<bool, ld> ans = fw();
        if(ans.st){
            cout << setprecision(15) << fixed << ans.nd << "\n";
            return 0;
        }
        ans = bw();
        if(ans.st){
            cout << setprecision(15) << fixed << ans.nd << "\n";
            return 0;
        }
    }
    return 0;
}