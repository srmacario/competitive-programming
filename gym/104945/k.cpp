#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define endl '\n'
#define double long double
// #define int long long
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    int n;
    cin >> n;
    ordered_set s;
    for(int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    vector<int> a(n / 2), b(n / 2);
    for(int i = 0; i < n / 2; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n / 2; i++) {
        cin >> b[i];
    }
    vector<int> p(n / 2), q(n / 2);
    for(int i = 0; i < n / 2; i++) {
        auto x = s.find_by_order(a[i] - 1);
        p[i] = *x;
        s.erase(x);
        x = s.find_by_order(b[i] - 1);
        q[i] = *x;
        s.erase(x);
    }
    for(int i = 0; i < n / 2; i++) {
        cout << p[i] << " \n"[i == n / 2 - 1];
    }
    for(int i = 0; i < n / 2; i++) {
        cout << q[i] << " \n"[i == n / 2 - 1];
    }
 
 
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;
    return 0;
}