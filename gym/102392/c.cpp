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
const int N = 260;

int n, mx, pos, level, pot, a[N], id[32][N], bn[N];
set<int> I[32][N];
vector<int> B[32][N];

vector<int> query_2(set<int>& s){
    //ask
    int sz = s.size();
    cout << "2 " << sz;
    for(auto u : s) cout << " " << u;
    cout << endl;

    //get ans
    vector<int> ans((sz * (sz - 1)) / 2);
    for(int i = 0; i < (sz * (sz - 1)) / 2; i++){
        cin >> ans[i];
        if(ans[i] == -1) exit(0);
    }
    return ans;
}

//v1 - v2;
vector<int> sub(vector<int> v1, vector<int> v2){
    for(auto u : v2){
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] == u){
                v1.erase(v1.begin() + i);
                break;
            }
        }
    }
    return v1;
}

//v1 inter v2 == v1 - (v1 - v2)
vector<int> inter(vector<int> v1, vector<int> v2){
    return sub(v1, sub(v1, v2));
}

vector<int> calc_init(set<int> s, vector<int> Qpos){
    vector<int> Q = query_2(s);
    vector<int> ans = sub(Qpos, Q);
    return ans;
}

vector<int> calc_b(set<int> s){
    vector<int> Q;
    if(s.size() > 1) Q = query_2(s);
    s.insert(pos);
    vector<int> Qpos = query_2(s);
    vector<int> ans = sub(Qpos, Q);
    return ans;
}

int get_mx(vector<int>& v){
    int ans = 0;
    for(auto u : v) ans = max(ans, u);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n <= 30){
        for(int i = 1; i <= n; i++){
            cout << "1 " << i << endl;
            cin >> a[i];
        }
        cout << "3";
        for(int i = 1; i <= n; i++) cout << " " << a[i];
        cout << endl;
        return 0;
    }
    while((1 << level) < (n - 1)) level++;
    pot = level;
    for(int i = 1; i <= n; i++) I[level][0].insert(i);

    //find max dist
    vector<int> ans = query_2(I[level][0]);
    mx = get_mx(ans);

    //binary search to find pos
    int l = 1, r = n;
    while(l < r){
        int m = (l + r)/2;
        if(m == 1){
            l = 2;
            break;
        }
        set<int> qry;
        for(int i = 1; i <= m; i++) qry.insert(i);
        vector<int> qry_ans = query_2(qry);
        int tmp = get_mx(qry_ans);

        if(tmp == mx) r = m;
        else l = m + 1;
    }
    pos = l;

    // //ask pos
    cout << "1 " << pos << endl;
    cin >> a[pos];
    if(a[pos] == -1) exit(0);

    //find B0 = 2 q
    I[level][0].erase(pos);
    B[level][0] = calc_init(I[level][0], ans);

    //D&C
    while(level){
        set<int> qry;
        int dif = (1 << (pot - level + 1)) - (1 << (pot - level));
        for(int i = 0; i < dif; i++){
            int cnt = 0;
            set<int> tmp;
            while(cnt < (1 << (level - 1))){
                if(I[level][i].empty()) break;
                qry.insert(*I[level][i].begin());
                tmp.insert(*I[level][i].begin());
                I[level][i].erase(I[level][i].begin());
                cnt++;
            }
            I[level - 1][2 * i] = tmp;
            I[level - 1][2 * i + 1] = I[level][i];
            for(auto u : tmp) I[level][i].insert(u);
        }
        vector<int> cur_b = calc_b(qry);
        for(int i = 0; i < dif; i++){
            if(I[level][i].empty()) continue;     
            if(I[level][i].size() == 1){
                B[level - 1][2 * i] = B[level][i];
                continue;
            }
            B[level - 1][2 * i] = inter(cur_b, B[level][i]);
            B[level - 1][2 * i + 1] = (sub(B[level][i], B[level - 1][2 * i]));
        }
        level--;
    }

    //find max bi
    pii bi_mx = {0, 0};
    for(int i = 0; i < n; i++){
        if(B[level][i].empty()) continue;
        bn[*I[level][i].begin()] = B[level][i][0];
    }
    for(int i = 1; i <= n; i++){
        if(i == pos) continue;
        bi_mx = max(bi_mx, make_pair(bn[i], i));
    }
    //ask bmax = |amax - amin|
    cout << "1 " << bi_mx.nd << endl;
    cin >> a[bi_mx.nd];
    if(a[bi_mx.nd] == -1) exit(0);

    // db(a[pos] _ a[bi_mx.nd]);
    for(int i = 1; i <= n; i++){

        if(i == bi_mx.nd or i == pos) continue;

        if(a[pos] > a[bi_mx.nd]) a[i] = a[pos] - bn[i];
        else a[i] = a[pos] + bn[i];
    }
    cout << "3";
    for(int i = 1; i <= n; i++) cout << " " << a[i];
    cout << endl;
    return 0;
}