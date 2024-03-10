#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 24, MAX = 1 << N;

ll n, a[MAX], f[MAX];
string s[MAX];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < MAX; i++) f[i]++;
    for(int i = 0; i < n; i++) cin >> s[i];
    
    for(int i = 0; i < N; i++){
        for(int m = MAX - 1; m >= 0; m--){
            if(m & (1 << i))
                f[m ^ (1 << i)] += f[m];
        }
    }
    for(int i = 0; i < MAX; i++){
        // cout << i << " " << f[i] << " ";
        f[i] = (MAX - f[i]);
        f[i] = f[i] * f[i];
        // cout << f[i] << "\n";
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int num = 0;
        for(auto ch : s[i]) num |= (1 << (ch - 'a'));
        num ^= (MAX  - 1);
        cout << num << " " << f[num] << "\n";
        ans ^= f[num];
    }
    cout << ans << "\n";
    return 0;
}