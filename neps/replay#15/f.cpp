#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

#ifndef ONLINEJUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

using ll = long long;
using ld = long double;

const ld INF = 1e12;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e2+5;

ll n, c, s, t;
ll x[N], y[N], r[N];
ld d[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n && n) {
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i] >> r[i];

      for (int j = 1; j <= n; j++) d[i][j] = INF + 10;
    } 

    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ll val = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
        if (val <= r[i] * r[i] + r[j] * r[j]) d[i][j] = sqrt(val);
      }
    }

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }

    cin >> c;
    while (c--) {
      cin >> s >> t;
      if (d[s][t] > INF) cout << -1 << "\n";
      else cout << trunc(d[s][t]) << "\n";
    }
  }
}