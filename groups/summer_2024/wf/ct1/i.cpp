#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <int mod = (int)1e9 + 7> struct modint {
    int x;
    modint(int y = 0) : x((y % mod + mod) % mod) { }
    friend modint operator ^ (modint a, long long b) {
        modint r = 1;
        for(; b; b >>= 1, a *= a) {
            if(b & 1) {
                r *= a;
            } 
        }
        return r;
    }
    friend modint operator - (modint a) {
        return modint(0) - a;
    }
    friend modint operator ! (modint a) {
        return a ^ (mod - 2);
    }
    modint& operator /= (modint const& b) {
        return *this *= !b;
    }
    friend modint operator + (modint a, modint const& b) {
        return a += b;
    }
    friend modint operator - (modint a, modint const& b) {
        return a -= b;
    }
    friend modint operator * (modint a, modint const& b) {
        return a *= b;
    }
    friend modint operator / (modint a, modint const& b) {
        return a /= b;
    }
    friend bool operator != (const modint &a, const modint b) {
        return a.x != b.x;
    }
    friend bool operator == (const modint &a, const modint b) {
        return a.x == b.x;
    }
    modint& operator *= (modint const& b) {
        x = 1ll * x * b.x % mod;
        return *this;
    }
    friend ostream& operator << (ostream& os, modint const& a) {
        return os << a.x;
    }
    modint& operator += (modint const& b) {
        x += b.x;
        x = (x >= mod) ? x - mod : x;
        return *this;
    }
    modint& operator -= (modint const& b) {
        x = x >= b.x ? x - b.x : x - b.x + mod;
        return *this;
    }
};

using mint = modint <998244353>;
vector<vector<vector<mint>>> dp(2, vector<vector<mint>>(205, vector<mint>(3, 0)));


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0] == -1) {
        for(int j = 1; j <= 200; j++) {
            dp[0][j][0] = 1;
        }
    } else {
        dp[0][a[0]][0] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 200; j++) {
            for(int k = 0; k < 3; k++) {
                dp[(i & 1)][j][k] = 0;
            }
        }
        if(a[i] == -1) {
            for(int j = 1; j <= 200; j++)
                dp[i & 1][j][0] = dp[i & 1][j - 1][0] + dp[(i - 1) & 1][j - 1][0] + dp[(i - 1) & 1][j - 1][2];
            for(int j = 200; j >= 1; j--)
                dp[i & 1][j][1] = dp[i & 1][j + 1][1] + dp[(i - 1) & 1][j + 1][1] + dp[(i - 1) & 1][j + 1][2];
            for(int j = 1; j <= 200; j++)
                dp[i & 1][j][2] = dp[(i - 1) & 1][j][0] + dp[(i - 1) & 1][j][1] + dp[(i - 1) & 1][j][2];
        } else {
            for(int j = 1; j < a[i]; j++)
                dp[i & 1][a[i]][0] += dp[(i - 1) & 1][j][0] + dp[(i - 1) & 1][j][2];
            for(int j = a[i] + 1; j <= 200; j++)
                dp[i & 1][a[i]][1] += dp[(i - 1) & 1][j][1] + dp[(i - 1) & 1][j][2];
            dp[i & 1][a[i]][2] = dp[(i - 1) & 1][a[i]][0] + dp[(i - 1) & 1][a[i]][1] + dp[(i - 1) & 1][a[i]][2];
        }
    }
    mint res = 0;
    for(int i = 1; i <= 200; i++) {
        res += dp[(n - 1) & 1][i][1] + dp[(n - 1) & 1][i][2];
    }
    cout << res << endl;
    end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
}