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

int n; //amount of points
pll pnt[N];
pll p1,p2;

struct cmp{
  bool operator()(pair<ll,ll> a, pair<ll, ll> b) { return a.nd < b.nd; }
};

double closest_pair() {
  sort(pnt, pnt+n);
  double best = numeric_limits<double>::infinity();
  set<pair<ll, ll>, cmp> box;

  box.insert(pnt[0]);
  int l = 0;

  for (int i = 1; i < n; i++){
    while(l < i and pnt[i].st - pnt[l].st > best)
      box.erase(pnt[l++]);
    for(auto it = box.lower_bound({0, pnt[i].nd - best}); it != box.end() and pnt[i].nd + best >= it->nd; it++)
      if(best > hypot(pnt[i].st - it->st, pnt[i].nd - it->nd)){
        best = hypot(pnt[i].st - it->st, pnt[i].nd - it->nd);
        p1 = pnt[i], p2.st = it->st, p2.nd = it->nd;
        //db(p1.st), db(p1.nd), db(p2.st), db(p2.nd);
      }
    box.insert(pnt[i]);
  }
  return best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++) cin >> pnt[i].st >> pnt[i].nd;
    closest_pair();
    //cout << closest_pair() << "\n";
    cout << p1.st << " " << p1.nd << "\n" << p2.st << " " << p2.nd << "\n";
    return 0;
}