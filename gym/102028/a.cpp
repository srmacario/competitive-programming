#include <bits/stdc++.h>
using namespace std;

int t, a;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            cin >> a;
            if (a) cnt++;
        }

        if (cnt == 0) cout << "Typically Otaku";
        if (cnt == 1) cout << "Eye-opener";
        if (cnt == 2) cout << "Young Traveller";
        if (cnt == 3) cout << "Excellent Traveller";
        if (cnt == 4) cout << "Contemporary Xu Xiake";
        cout << "\n";
    }
}