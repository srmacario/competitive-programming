// One, two, three, let's go 저 바다 건너 들릴 듯 소리 질러
// corner cases // int vs ll // clear structures // statement // doublesz // line order // 0-1-indexed
#include <bits/stdc++.h>
#define endl '\n'
#define REP(i, a, b) for (int i = int(a), gg = int(b); i < gg; ++i)
#define trace(x) cerr << #x << " = " << x << endl
using namespace std;
typedef long long Long;

struct Hash {
  int P = 1777771, MOD[2], PI[2];
  vector<int> h[2], pi[2];
  Hash(string &s) {
    MOD[0] = 999727999; MOD[1] = 1070777777;
    PI[0] = 325255434; PI[1] = 10018302;
    REP(k, 0, 2) h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
    REP(k, 0, 2) {
      h[k][0] = 0;
      pi[k][0] = 1;
      Long p = 1;
      REP(i, 1, s.size() + 1) {
        h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
        pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
        p = (p * P) % MOD[k];
      }
    }
  }
  Long get(int s, int e) {
    Long h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
    h0 = (1LL * h0 * pi[0][s]) % MOD[0];
    Long h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
    h1 = (1LL * h1 * pi[1][s]) % MOD[1];
    return (h0 << 32) | h1;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  while (cin >> m) {
    if (m == 0) break;
    string s;
    cin >> s;
    int n = s.size();
    Hash hsh(s);
    pair<int, int> ans;
    int lo = 0, hi = n + 1;
    
    unordered_map<Long, int> mp;
    auto test = [&](int len) {
      int best = 0;
      mp.clear();
      for (int i = 0; i + len <= n && best < m; ++i) {
        Long now = hsh.get(i, i + len);
        mp[now]++;
        best = max(best, mp[now]);
      }
      return best >= m;
    };

    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (test(mid)) lo = mid;
      else hi = mid;
    }

    if (lo == 0) {
      cout << "none" << endl;
      continue;
    }

    int last = -1;
    mp.clear();
    for (int i = 0; i + lo <= n; ++i) {
      Long now = hsh.get(i, i + lo);
      mp[now]++;
      if (mp[now] >= m) {
        last = i;
      }
    }

    cout << lo << " " << last << endl;

  }

  return 0;
}
