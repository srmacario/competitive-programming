#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Info {
  int a, b, p;
};

vector<Info> info;
vector<int> vals;
vector<pair<int, int>> adj[N];
int ptr[N];

vector<int> false_not_c, false_c;

int n, c;
int a, b, w;
bool add;

vector<int> ans;

void dfs(int x) {
  if (x != c and !add) {
    for (auto f : false_c) ans.push_back(f);
    add = true;
  }

  if (ptr[x] == adj[x].size()) return;

  pair<int, int> nxt = adj[x][ptr[x]];
  ptr[x]++;

  ans.push_back(nxt.second);
  dfs(nxt.first);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> c;
  vals.push_back(c);
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> w;
    vals.push_back(a);
    vals.push_back(b);
    if (w == 1) {
      info.push_back({ a, b, i });
    } else {
      if (a != c) false_not_c.push_back(i);
      else false_c.push_back(i);
    }
  }

  ans = false_not_c;

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  c = int(lower_bound(vals.begin(), vals.end(), c) - vals.begin());

  for (auto infox : info) {
    int ax = infox.a;
    int bx = infox.b;
    ax = int(lower_bound(vals.begin(), vals.end(), ax) - vals.begin());
    bx = int(lower_bound(vals.begin(), vals.end(), bx) - vals.begin());
    adj[ax].push_back({ bx, infox.p });
  }

  for (int i = 0; i < vals.size(); i++) sort(adj[i].begin(), adj[i].end());

  dfs(c);

  if (ans.size() != n) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  for (auto a : ans) cout << a << " ";
  cout << "\n";
}