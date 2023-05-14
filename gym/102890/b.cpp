#include <bits/stdc++.h>
#include <random>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3ff3, MOD = 1e9+7;
const int N = 1e5+5;

mt19937_64 llrand(random_device{}());

struct node {
    int val;
    int cnt;
    int left, right, mx;
    ll pri;
    node* l;
    node* r;

    node() {}
    node(int x) : val(x), cnt(1), left(1), right(1), mx(1), pri(llrand()), l(0), r(0) {}
};

struct treap {
    node* root;
    treap() : root(0) {}
    ~treap() { clear(); }

    int cnt(node* t) { return t ? t->cnt : 0; }
    int left(node* t) { return t ? t->left : 0; }
    int right(node* t) { return t ? t->right : 0; }
    int mx(node* t) { return t ? t->mx : 0; }

    void clear() { del(root); }
    void del(node* t) {
        if (!t) return;
        del(t->l);
        del(t->r);
        delete t;
        t = 0;
    }

    void update(node*& t) {
        if (!t) return;
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
        // left
        if (left(t->l) == cnt(t->l)) {
            if (get_last(t->l) == t->val) {
                if (get_first(t->r) == t->val) t->left = left(t->l) + 1 + left(t->r);
                else t->left = left(t->l) + 1;
            } else t->left = left(t->l);
        } else {
            t->left = left(t->l);
        }

        // right
        if (right(t->r) == cnt(t->r)) {
            if (get_first(t->r) == t->val) {
                if (get_last(t->l) == t->val) t->right = right(t->r) + 1 + right(t->l);
                else t->right = right(t->r) + 1;
            } else t->right = right(t->r);
        } else {
            t->right = right(t->r);
        }

        t->mx = max(mx(t->l), mx(t->r));
        if (get_last(t->l) == get_first(t->r)) {
            t->mx = max(t->mx, right(t->l) + left(t->r));
        }
    }

    node* merge(node* l, node* r) {
        node* t;
        if (!l or !r) t = l ? l : r;
        else if (l->pri > r->pri) l->r = merge(l->r, r), t = l;
        else r->l = merge(l, r->l), t = r;
        update(t);
        return t;
    }

    pair<node*, node*> split(node* t, int pos) {
        if (!t) return { 0, 0 };

        if (cnt(t->l) < pos) {
            auto x = split(t->r, pos-cnt(t->l)-1);
            t->r = x.st;
            update(t);
            return { t, x.nd };
        }

        auto x = split(t->l, pos);
        t->l = x.nd;
        update(t);
        return { x.st, t };
    }

    void insert(int pos, int val) {
        node* x = new node(val);
        auto t = split(root, pos);
        root = merge(merge(t.st, x), t.nd);
    }

    void append(int val) {
        node* x = new node(val);
        root = merge(root, x);
    }

    void erase(int pos) {
        auto t1 = split(root, pos);
        auto t2 = split(t1.nd, 1);
        delete t2.st;
        root = merge(t1.st, t2.nd);
    }

    int get_first(node* t) {
        if (t == nullptr) return 0;
        return get_val(t, 0);
    }

    int get_last(node* t) {
        if (t == nullptr) return 0;
        return get_val(t, cnt(root) - 1);
    }

    int get_val(int pos) { return get_val(root, pos); }
    int get_val(node* t, int pos) {
        if (cnt(t->l) == pos) return t->val;
        if(cnt(t->l) < pos) return get_val(t->r, pos-cnt(t->l)-1);
        return get_val(t->l, pos);
    }

    int get_mx() {
        if (mx(root) == cnt(root)) return cnt(root);
        int ans = mx(root);
        if (get_first(root) == get_last(root)) {
            ans = max(ans, left(root) + right(root));
        }
        return ans;
    }
};

int n, q;
int c[N];

struct query {
    int t, d, a, b;
};

query qs[N];

pair<int, int> get_pos(int id) {
    // 
}

vector<treap> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    v.push_back(treap());

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= q; i++) {
        cin >> qs[i].t >> qs[i].d >> qs[i].a;
        if (qs[i].t == 1) cin >> qs[i].b;
    }

    for (int i = 1; i <= n; i++) {
        v.back().append(c[i]);
    }

    for (int i = 1; i <= q; i++) {
        int id = n + 1;
        if (qs[i].t == 1) {
            auto [ array_id_a, array_pos_a ] = get_pos(qs[i].a);
            auto [ array_id_b, array_pos_b ] = get_pos(qs[i].b);

            if (array_pos_a > array_pos_b) swap(array_pos_a, array_pos_b);
            
        }
    }



    return 0;
}