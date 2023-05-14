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
const int MX = 3e8 + 5;
const char c = '#';

int x, cnt;
string inp;

vector<int> e, d, sum;
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return (int)sum.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        sum[pos] += val;
        return;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        if(e[pos] == 0){
            int aux = create();
            e[pos] = aux;
        }
        update(e[pos], ini, m, id, val);
    }
    else{
        if(d[pos] == 0){
            int aux = create();
            d[pos] = aux;
        }
        update(d[pos], m + 1, fim, id, val);
    }

    sum[pos] = sum[e[pos]] + sum[d[pos]];
}

int query(int pos, int ini, int fim, int val){
    if(ini == fim){
        update(1, 1, MX, ini, -1);
        return ini;
    }

    int left_sum = sum[e[pos]];

    int m = (ini + fim) >> 1;
    if(left_sum >= val){
        return query(e[pos], ini, m, val);
    }

    return query(d[pos], m + 1, fim, val - left_sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    create();
    create();

    while(cin >> inp){
        if(inp == "#"){
            if(cnt % 2) cout << query(1, 1, MX, (cnt + 1) / 2) << "\n";
            else cout << query(1, 1, MX, cnt/2 + 1) << "\n";
            cnt--;
        }
        else{
            x = stoi(inp);
            // if(x == -1) return 0;
            update(1, 1, MX, x, 1);
            cnt++;
        }
    }

    return 0;
}