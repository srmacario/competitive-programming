/*
    Rectangles form a graph! The number of leaves are the answer, just line sweep and do a smart check to see its a leaf
*/

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int st[4*N], lazy[4*N];
int xtl[N], ytl[N], xbr[N], ybr[N];
int n, ans;
set<int> nodes;
vector<int> vx, vy;

void push (int p, int l, int r) {
    if (lazy[p] != -1) {
        st[p] = lazy[p];
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
        lazy[p] = -1;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = min(st[2*p], st[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //set lazy to -1
    memset(lazy, -1, sizeof lazy);
    cin >> n;

    //read
    for(int i = 1; i <= n; i++){
        cin >> xtl[i] >> ytl[i] >> xbr[i] >> ybr[i];
        vx.push_back(xtl[i]);
        vx.push_back(xbr[i]);
        vy.push_back(ytl[i]);
        vy.push_back(ybr[i]);
    }

    //coordinate compression
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());

    vector<pair<pair<int, int>, pair<int, int>>> events;
    for(int i = 1; i <= n; i++){
        xtl[i] = int(lower_bound(vx.begin(), vx.end(), xtl[i]) - vx.begin());
        xbr[i] = int(lower_bound(vx.begin(), vx.end(), xbr[i]) - vx.begin());
        ytl[i] = int(lower_bound(vy.begin(), vy.end(), ytl[i]) - vy.begin());
        ybr[i] = int(lower_bound(vy.begin(), vy.end(), ybr[i]) - vy.begin());

        //creating events (opening and closing rectangles)
        //description: {{x, y}, {open/close, id}}
        //open = 0, close = 1
        events.push_back({{xtl[i], ytl[i]}, {0, i}});
        events.push_back({{xbr[i], ybr[i]}, {1, i}});
    }
    //line sweep
    sort(events.begin(), events.end());
    for(auto e : events){
        if(e.nd.st == 0){
            update(1, 0, N - 1, ybr[e.nd.nd], ytl[e.nd.nd], e.nd.nd);
        }
        else{
            //if the min in range of the closing rectangle is his own value, so this rectangle is a leaf, increase ans
            if(query(1, 0, N - 1, ybr[e.nd.nd], ytl[e.nd.nd]) == e.nd.nd) ans++;
            update(1, 0, N - 1, ybr[e.nd.nd], ytl[e.nd.nd], 0);
        }

    }
    cout << ans << "\n";
    return 0;
}

/*
    st[1]
    st[2]
    st[3]
    st[4]
    st[5]
    st[6]
    st[7]
    st[8]


*/