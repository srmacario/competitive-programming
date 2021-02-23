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
const int K = 52;
const int N = 1e5+5;

int idc(char c){
    if(c < 'a') return c - 'A' + 26;
    else return c - 'a';
}

struct Aho{

    struct Vertex{
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        int sum = 0;

        Vertex(int par = -1, char ch = '$') : p(par), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };  

    vector<Vertex> t;

    Aho() : t(1){}

    void add_string(const string& s, int id){
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            if(t[v].next[c] == -1){
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].sum++;
    }

    int get_link(int v){
        if(t[v].link == -1){
            if(v == 0 || t[v].p == 0) t[v].link = 0;
            else t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch){
        int c = idc(ch);
        if(t[v].go[c] == -1){
            if(t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
            else t[v].go[c] = (v == 0) ? 0 : go(get_link(v), ch);
            t[v].sum += t[t[v].go[c]].sum;        
        }
        return t[v].go[c];
    }

    int run(const string& s){
        int ans = 0;
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            db(v _ t[v].sum);
            ans += t[v].sum;
            v = t[v].next[c];
            if(v == -1) v = 0;
        }
        db(v _ t[v].sum);
        ans += t[v].sum;
        return ans;
    }
};

string a[N];

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    Aho aho;
    for(int i=1;i<=k;i++){
        cin >> a[i];
        aho.add_string(a[i],i);
    }
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c == '-'){
            int op;
            cin >> op;
            db(op);
        }
        if(c == '+'){
            int op;
            cin >> op;
            //aho.add_string(a[op], op);
        }
        if(c == '?'){
            string s;
            cin >> s;
            cout << aho.run(s) << "\n";
        }
    }
    return 0;
}