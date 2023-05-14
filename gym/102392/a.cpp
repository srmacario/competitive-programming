#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, v[N], a[N], len[N], sum;
vector<int> num[N];

ll ini[4*N], lazy[4*N];

void push (int p, int l, int r) {
    if (lazy[p]) {
        ini[p] = (r - l + 1)*lazy[p];
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p + 1] = lazy[p];
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p] = 0;
    }
}

ll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return ini[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x + y;
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    ini[p] = ini[2*p] + ini[2*p+1];
}

ll get_ini(int p){
    return query(1, 1, n, p, p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];

        a[i] = 1;
        len[i] = 1;
        update(1, 1, n, i, i, i);

        num[v[i]].push_back(i);
    }
    for(int i = 1; i <= m; i++){
        if(num[i].empty()){
            cout << "-1 ";
            continue;
        }
        //upd a = 0
        for(auto pos : num[i]){
            int current_ini = get_ini(pos);
            //check if its endpoint of an alternate sequence
            if(current_ini + len[current_ini] - 1 == pos){
                //update sum removing old len and adding new len
                //      old len                 new len
                sum -= (len[current_ini] / 2 - (len[current_ini] - 1) / 2);
                len[current_ini]--;
            }
            //otherwise, split
            else{
                //update sum removing old len and adding new lens
                //      old len              new len 1              new len 2             
                sum -= (len[current_ini]/2 - (pos - current_ini)/2 - (len[current_ini] - (pos - current_ini + 1))/2);

                //change new initial point for every one in range [pos + 1, current_ini + len[current_ini] - 1], which is the second sequence
                update(1, 1, n, pos + 1, current_ini + len[current_ini] - 1, pos + 1);
                
                //update new lengths
                len[pos + 1] = (len[current_ini] - (pos - current_ini + 1));
                len[current_ini] = (pos - current_ini);
            }
            a[pos] = len[pos] = 0;
            update(1, 1, n, pos, pos, pos);
        }
        //care with the cycles
        int ans = n - num[i].size() + sum;
        if(a[1] != a[n] and a[1] != 0 and a[n] != 0){
            int ini_n = get_ini(n);
            ans = ans - len[1]/2 - len[ini_n]/2 + (len[1] + len[ini_n])/2;
        }
        cout << ans << " ";
        
        //upd a = -1
        for(auto pos : num[i]){
            a[pos] = -1;
            len[pos] = 1;
            update(1, 1, n, pos, pos, pos);
            //check if p is now a initial point of an alternate sequence
            if(pos < n and a[pos + 1] == 1){
                //update sum removing old len and adding new len
                //      new len                old len
                sum += (len[pos + 1] + 1)/2 - (len[pos + 1])/2;
                //change new initial point for every one in range [pos + 1, pos + len[pos + 1]], which is the current sequence
                update(1, 1, n, pos + 1, pos + len[pos + 1], pos);

                //change lens
                len[pos] = len[pos + 1] + 1;
                len[pos + 1] = 0;
            }
            // check if p is now a final point of an alternate sequence
            if(pos > 1 and a[pos - 1] == 1){
                //update sum by removing sequence starting at pos and plugging it in sequence starting at ini[pos - 1]
                int current_ini = get_ini(pos - 1);
                //      new len                         old len 1               old len 2
                sum += (len[current_ini] + len[pos])/2 - (len[current_ini])/2 - (len[pos])/2;
                
                //change new initial point for every one in range [pos, pos + len[pos] - 1], which is the current sequence
                update(1, 1, n, pos, pos + len[pos] - 1, current_ini);
                //change lens
                len[current_ini] = len[current_ini] + len[pos];
                len[pos] = 0;
            }
        }
    }
}