#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ld = long double;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4 + 5;

ll a, b, c;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> a && a) {
    cin >> b >> c;
    ld val = a * b * (long double)(100/c);
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        if(i * i * c == a * b * 100){
            ans = i;
            break;
        }
        if(i * i * c > a * b * 100){
            ans = i - 1;
            break;
        }
    }
    cout << ans << "\n";
  }
}

//a * b * 100 = i * i * c