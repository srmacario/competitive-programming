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

struct line{
    //l: ax + b
    //{num_a, den_a}, {num_b, den_b}
    pll a, b;
    line(pll p0, pll p1){
        if(p0.st == p1.st){
            a = {INF, 1};
            b = {(p1.st), 1};
        }
        else if(p0.nd == p1.nd){
            a = {0, 1};
            b = {(p1.nd), 1};
        }
        else{
            //y = ax + b => den_b = den_a, num_b = y0*den_a - num_a * x0  
            a.st = (p1.nd - p0.nd), a.nd = (p1.st - p0.st);
            ll gcd = __gcd(a.st, a.nd);
            a.st /= gcd, a.nd /= gcd;

            b.st = (p0.nd * a.nd) - (p0.st * a.st), b.nd = a.nd;
            gcd = __gcd(b.st, b.nd);
            b.st /= gcd, b.nd /= gcd;
        }
    }

    bool operator < (const line &l) const{
        if(a == l.a) return b < l.b;
        return a < l.a;
    }
};


int n;
pll triangles[N][3];
// line -> {open, {edge, id}}
map<line, vector<pair<int, pair<pll, int>>>> sweep;

ll cross(pll a, pll b){
    return (a.st * b.nd - a.nd * b.st);
}

ll area_2(int i){
    return cross(triangles[i][0], triangles[i][1]) + cross(triangles[i][1], triangles[i][2]) + cross(triangles[i][2], triangles[i][0]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < 3; k++) cin >> triangles[i][k].st >> triangles[i][k].nd;
        for(int k = 0; k < 3; k++){
            line l = line(triangles[i][k], triangles[i][(k + 1)%3]);
            sweep[l].push_back({0, {min(triangles[i][k], triangles[i][(k + 1)%3]), i}});
            sweep[l].push_back({1, {max(triangles[i][k], triangles[i][(k + 1)%3]), i}});
        }
    }
    set<int> ans_index;
    for(auto cur : sweep){
        sort(cur.nd.begin(), cur.nd.end());
        // db(cur.st.a.st _ cur.st.a.nd _ cur.st.b.st _ cur.st.b.nd);
        // db(cur.nd.size());
        set<int> cur_index;
        for(int i = 0; i < cur.nd.size(); i++){
            pair<int, pair<pll, int>> cur_event = cur.nd[i];
            while(i + 1 < cur.nd.size() and cur_event.nd.st == cur.nd[i + 1].nd.st){
                if(cur_event.st == 0) cur_index.insert(cur_event.nd.nd);
                else cur_index.erase(cur_event.nd.nd);

                cur_event = cur.nd[++i];
            }
            // db(i);            
            if(cur_event.st == 0) cur_index.insert(cur_event.nd.nd);
            else cur_index.erase(cur_event.nd.nd);
            if(cur_index.size() == 1) ans_index.insert(*cur_index.begin());
        }
    }
    ll tot = 0;
    for(auto u : ans_index){
        db(u);
        ll a = abs(area_2(u));
        db(a);
        tot += a;
    }
    for(int i = 0; i < n; i++) db(abs(area_2(i)));
    cout << tot/2 << ".";
    if(tot%2) cout << "5\n";
    else cout << "0\n";
    return 0;
}