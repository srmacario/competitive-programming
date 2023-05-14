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

struct Node {
    int cnt = 0;
    Node* ch[27];
    Node () : cnt(0) {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (string s) {
    Node* cur = root;
    cur->cnt++;
    for (auto c : s) {
        if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
        cur = cur->ch[c-'a'];
        cur->cnt++;
    }
    if (!cur->ch[26]) cur->ch[26] = new Node();
    cur = cur->ch[26];
    cur->cnt++;
}

int match (string s) {
    Node* cur = root;
    for (auto c : s) {
        if (!cur->ch[c-'a']) return false;
        cur = cur->ch[c-'a'];
    }
    if (!cur->ch[26]) return false; // If you only need to count prefixes (not
                                    // the exact word), comment this line
    return cur->cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root = new Node();
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        int x;
        cin >> x;
        string cur;
        for(int j = 0; j < x; j++){
            char y;
            cin >> y;
            cur += y;
        }
        if(c == 'C'){
            add(cur);
        }
        if(c == 'J'){
            
        }
        if(c == 'D'){
            
        }
    }
    return 0;
}