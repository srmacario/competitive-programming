#include <bits/stdc++.h>
using namespace std;

int n, x;
bool done[720];
int inp[1000];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> inp[i];
    inp[i] += 180;
    inp[i] *= 2;
  }

  inp[n] = inp[0];

  for (int i = 1; i <= n; i++) {
    int mn = min(inp[i], inp[i-1]);
    int mx = max(inp[i], inp[i-1]);
    int val = mx - mn;

    if (val == 360) {
      for (int k = 0; k < 720; k++) {
        done[k] = true;
      }
    } else if (val < 720 - val) {
      for (int k = mn; k <= mx; k++)
        done[k] = true;
    } else {
      for (int k = mn; k >= 0; k--)
        done[k] = true;
      for (int k = 719; k >= mx; k--)
        done[k] = true;
    }
  }

  for (int i = 0; i < 720; i++)
    if (!done[i]) {
      cout << fixed << setprecision(1) << "no " << 
        i/2.0 - 180 << "\n";
      return 0;
    }

  cout << "yes\n";
}