#include <bits/stdc++.h>
using namespace std;
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
using ll = long long;
using ld = long double;
 
const int N = 5e3+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 
int lps[N];

ll pre_kmp(string& p) {
    ll sum = 0;
    for (int l = 0; l < (int)p.size(); l++) {
        lps[l] = 0;
        for (int i = l + 1, j = l; i < (int)p.size(); i++) {
            while (j != l and p[j] != p[i]) j = lps[j - 1] + l;
            if (p[j] == p[i]) j++;
            lps[i] = j - l;
        }
 
        for (int i = l; i < (int)p.size(); i++) 
            if (lps[i] != (l - i + 1)) sum += lps[i];
    }
 
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    string s;
    while (cin >> s) {
        cout << pre_kmp(s) << "\n";
    }
 
    return 0;
}