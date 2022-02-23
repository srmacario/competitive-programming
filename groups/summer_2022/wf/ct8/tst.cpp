#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <random>
using namespace std;
 
mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());
 
#define st first
#define nd second
 
#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif
 
using ll = long long;
using ld = long double;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;
 
struct Vector {
  ll x, y;
  Vector(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
 
  ll dist(Vector b) {
    return (b.x - x) * (b.x - x) + (b.y - y) * (b.y - y);
  }
 
  bool operator<(const Vector& b) const {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
};
 
Vector origin;
 
map<Vector, vector<Vector>> mp;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, cnt = 0;
  ll x0, y0, r;
  cin >> x0 >> y0 >> r >> n;
  origin = Vector(x0, y0);
  ll x, y;
  while (n--) {
    cin >> x >> y;
    mp[Vector(x - x0, y - y0)].push_back(Vector(x, y));
  }
 
  for (auto& x : mp) {
    for (auto v : x.second) {
      if (v.dist(origin) <= r * r) {
        cnt++;
        break;
      }
    }
  }
 
  cout << cnt << "\n";
}