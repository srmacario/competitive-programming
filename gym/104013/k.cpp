#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

// op == 0: or
// op == 1: and

bool calc(bool val1, bool val2, bool op) {
  if (!op) return val1 or val2;
  return val1 and val2;
}

struct Node {
  bool _not = false;
  int idx = -1;
  vector<Node*> children;
  vector<bool> ops;

  bool eval(int &values) {
    if (children.empty()) {
        bool ans = values & (1 << idx);
        if (_not) return !ans;
        return ans;
    }

    bool ans = children[0] -> eval(values);
    for (int i = 1; i < (int)children.size(); i++) {
      ans = calc(ans, children[i] -> eval(values), ops[i-1]);
    }

    if (_not) return !ans;
    return ans;
  }
};

void del(Node* node) {
  for (auto x : node -> children) del(x);
  delete node;
}

Node* parse(string& s, int i, int j) {
  bool _not = false;
  if (s[i] == 'n') {
    _not = true;
    i += 3;
    while (i <= j and s[i] == ' ') i++;
    assert(i <= j);
  }

  if (i == j) {
    Node* x = new Node();
    x -> _not = _not;
    x -> idx = int(s[i] - 'a');
    return x;
  }

  while (i <= j and s[i] == ' ') i++;
  assert(i <= j);

  vector<Node*> children;
  vector<bool> ops;

  while (i <= j) {
    int k = i;
    if (s[i] == 'n') {
      k += 3;
      while (k <= j and s[k] == ' ') k++;
      assert(k <= j);
    }
    if (s[i] == '(') {
      int cnt = 0;
      while (k <= j) {
        if (s[k] == '(') cnt++;
        if (s[k] == ')') cnt--;
        if (!cnt) break;
        k++;
      }
      assert(k <= j);
      children.push_back(parse(s, i + 1, k - 1));
    } else {
      children.push_back(parse(s, i, k));
    }

    k++;
    while (k <= j and s[k] == ' ') k++;
    if (k <= j) {
      if (s[k] == 'o') ops.push_back(false), k += 2;
      else ops.push_back(true), k += 3;
      while (k < j and s[k] == ' ') k++;
      assert(k <= j);
    }

    i = k;
  }

  Node* x = new Node();
  x -> idx = -1;
  x -> _not = _not;
  x -> children = children;
  x -> ops = ops;

  return x;
}

string s;
Node* root;

bool table[1 << 8];

int child[1 << 8][2], trien = 0;

vector<string> plug(vector<string> a, vector<string> b){
    if(a.size() == 0) return b;
    if(b.size() == 0) return a;
    int h = max(a.size(), b.size()), w = max(a[0].size(), b[0].size());
    a.resize(h), b.resize(h);
    for(int i = 0; i < h; i++){
        a[i].resize(w), b[i].resize(w);
        a[i] += b[i];
    }
    return a;
}

vector<string> build(int node, int mask, int cur){
    if(cur == 8 or !(child[node][0] or child[node][1])){
        vector<string> ans;
        for(int i = 0; i < 8; i++){
            char c = i + 'a';
            string ch;
            ch += c;
            string line = "-+" + ch + "+-";
            if( (1 << i) & mask ){
                if(ans.size()){
                    ans.push_back(" | | ");
                }
                ans.push_back(line);
            }
        }
        db(mask);
        for(auto a : ans) cout << a << "\n";
        return ans;
    }
    db(cur _ child[node][0] _ child[node][1]);
    vector<string> ans;
    if(child[node][0]){
        plug(ans, build(child[node][0], mask, cur + 1));
    }
    if(child[node][1]){
        vector<string> u;
        u.push_back("+");
        if(child[node][0]) ans = plug(ans, u);
        plug(ans, build(child[node][1], mask & (1 << cur), cur + 1));
    }
    return ans;
}

void ins(int u, int p, int b){
 if(p == 8)
  return;
 if(!child[u][(b >> p) & 1])
  child[u][(b >> p) & 1] = ++trien;
 ins(child[u][(b >> p) & 1], p + 1, b);
}

int main () {
  ios_base::sync_with_stdio(0), cin.tie(0);
  getline(cin, s);
  root = parse(s, 0, (int)s.size() - 1);

  for (int i = 0; i < (1 << 8); i++) table[i] = root -> eval(i);

  del(root);
  
 for(int i = 0; i < (1 << 8); i++)
  if(table[i])
   for(int j = 0; j < 8; j++)
    if(!(i & (1 << j)))
     if(!table[i | (1 << j)]){
      cout << "IMPOSSIBLE\n";
      return 0;
     }
 for(int i = (1 << 8) - 1; i >= 0; i--)
  if(table[i])
   for(int j = 0; j < 8; j++)
    if(!(i & (1 << j)))
     table[i | (1 << j)] = false;
 for(int i = 0; i < (1 << 8); i++)
  if(table[i])
   ins(0, 0, i);
    vector<string> ans = build(0, 0, 0);
   for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}