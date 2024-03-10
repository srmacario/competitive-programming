//Слава Україні, Героям слава

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> ans;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    sort(a.begin(), a.end());
    // a[0] + mx;
    multiset<int> tmp(b.begin(), b.end());
    int cur = a[0] + mx;
    bool foi = true;
    for(int i = 0; i < n; i++) {
        int x = abs(cur - a[i]);
        if(tmp.find(x) != tmp.end()) {
            tmp.erase(tmp.find(x));
        } else {
            foi = false;
            break;
        }
    }
    if(foi) ans.insert(a[0] + mx);
    tmp = multiset<int>(b.begin(), b.end());
    foi = true;
    cur = a[n - 1] - mx;
    for(int i = 0; i < n; i++) {
        int x = abs(cur - a[i]);
        if(tmp.find(x) != tmp.end()) {
            tmp.erase(tmp.find(x));
        } else {
            foi = false;
            break;
        }
    }
    if(foi) ans.insert(a[n - 1] - mx);
    for(auto e : ans) {
        cout << e << "\n";
    }
    return 0;
}