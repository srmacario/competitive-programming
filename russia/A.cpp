#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (n+1)/2; i++) sum -= v[i];

    cout << sum << "\n";

}