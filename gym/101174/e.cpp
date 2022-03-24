#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e6 + 3;
const int N = 1e5 + 5;

int A, B;

template<int ALPHA_SIZE = 36>
struct Aho {
    struct Node {
        int p, char_p, link = -1, nxt[ALPHA_SIZE];
        bool has_end = false;
        Node (int _p = -1, int _char_p = -1) : p(_p), char_p(_char_p) {
            fill(nxt, nxt + ALPHA_SIZE, -1);
        }
    };

    vector<Node> nodes = { Node() };
    bool build_done = false;

    int remap(char c) {
        if (islower(c)) return c - 'a';
        if (isalpha(c)) return c - 'A';
        if (c == '0') return 'o' - 'a';
        if (c == '1') return 'i' - 'a';
        if (c == '3') return 'e' - 'a';
        if (c == '5') return 's' - 'a';
        if (c == '7') return 't' - 'a';
        return c - '0' + 26;
    }

    void add(string& p) {
        int u = 0;

        for (char ch : p) {
            int c = remap(ch);
            if (nodes[u].nxt[c] == -1) {
                nodes[u].nxt[c] = (int)nodes.size();
                nodes.push_back(Node(u, c));
            }

            u = nodes[u].nxt[c];
        }

        nodes[u].has_end = true;
    }

    void build() {
        build_done = true;
        queue<int> q;
        
        for (int i = 0; i < ALPHA_SIZE; i++) {
            if (nodes[0].nxt[i] != -1) q.push(nodes[0].nxt[i]);
            else nodes[0].nxt[i] = 0;
        }

        while (q.size()) {
            int u = q.front();
            q.pop();

            int j = nodes[nodes[u].p].link;
            if (j == -1) nodes[u].link = 0;
            else nodes[u].link = nodes[j].nxt[nodes[u].char_p];

            nodes[u].has_end |= nodes[nodes[u].link].has_end;

            for (int i = 0; i < ALPHA_SIZE; i++) {
                if (nodes[u].nxt[i] != -1) q.push(nodes[u].nxt[i]);
                else nodes[u].nxt[i] = nodes[nodes[u].link].nxt[i];
            }
        }
    }

    // dp[node][bitmask (has lower, upper, digit)][size]

    struct Info {
        int node;
        int mask;
        int size;

        bool operator<(const Info& b) const {
            if (node == b.node and mask == b.mask) return size < b.size;
            if (node == b.node) return mask < b.mask;
            return node < b.node;
        }
    };

    ll add(ll a, ll b) {
        //if (a >= MOD - b) return a + b - MOD;
        return a + b;
    }

    ll calc_dp() {
        if (build_done == false) build();

        int sz = (int)nodes.size();
        map<Info, bool> vis;
        vector<ll> dp[8][25];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 25; j++) 
                dp[i][j].resize(sz);
        }

        Info s = { 0, 0, 0 };
        dp[0][0][0] = 1;
        vis[s] = true;
        queue<Info> q;
        q.push(s);

        while (q.size()) {
            Info u = q.front();
            q.pop();

            if (u.size == B + 1) continue;

            for (int i = 0; i < 62; i++) {
                int new_mask = u.mask;
                int ni = i;

                if (ni < 26) {
                    new_mask |= 1;
                } else if (ni >= 26 and ni < 52) {
                    new_mask |= 2;
                    ni -= 26;
                } else {
                    new_mask |= 4;
                    ni -= 52;
                    if (ni == 0) ni = 'o' - 'a';
                    else if (ni == 1) ni = 'i' - 'a';
                    else if (ni == 3) ni = 'e' - 'a';
                    else if (ni == 5) ni = 's' - 'a';
                    else if (ni == 7) ni = 't' - 'a';
                }

                int nxt_node = nodes[u.node].nxt[ni];
                if (nodes[nxt_node].has_end) continue;

                Info v = { nxt_node, new_mask, u.size + 1 };
                dp[v.mask][v.size][v.node] = add(dp[v.mask][v.size][v.node], dp[u.mask][u.size][u.node]);

                if (vis[v] == false) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        ll ans = 0;
        for (int i = A; i <= B; i++) {
            for (int j = 0; j < sz; j++) {
                ans = add(ans, dp[7][i][j]);
            }
        }

        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    int n;
    cin >> n;

    string s;

    Aho<> aho;

    while(n--) {
        cin >> s;
        aho.add(s);
    }

    cout << aho.calc_dp() << "\n";

    return 0;
}