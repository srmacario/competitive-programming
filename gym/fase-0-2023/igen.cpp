#include <bits/stdc++.h> 
#include <chrono> 
#define endl '\n' 
using namespace std; 
typedef long long ll; 
typedef unsigned long long ull; 
#define double long double 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
#define int long long 
const int mod = 998'244'353; 
main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int t = 1; 
    // cin >> t; 
    while(t--) { 
    for(int fuck = 0; fuck < (1 << 10); fuck++) { 
        // cout << fuck << ": "; 
        vector<int> op(12), cur(10); 
        op[1] = (1 << 2) + (1 << 5); 
        op[2] = (1 << 1) + (1 << 3) + (1 << 5) + (1 << 6); 
        op[3] = (1 << 2) + (1 << 4) + (1 << 6) + (1 << 7); 
        op[4] = (1 << 3) + (1 << 7); 
        op[5] = (1 << 1) + (1 << 2) + (1 << 6) + (1 << 8); 
        op[6] = (1 << 2) + (1 << 3) + (1 << 5) + (1 << 7) + (1 << 8) + (1 << 9); 
        op[7] = (1 << 3) + (1 << 4) + (1 << 6) + (1 << 9); 
        op[8] = (1 << 5) + (1 << 6) + (1 << 9) + (1 << 10); 
        op[9] = (1 << 6) + (1 << 7) + (1 << 8) + (1 << 10); 
        op[10] = (1 << 8) + (1 << 9); 
        int curn = 0; 
        for(int i = 0; i < 10; i++) { 
            // cin >> cur[i]; 
            cur[i] = (fuck & (1 << i)) != 0; 
            // cout << cur[i] << " "; 
            if(cur[i]) { 
                curn += (1 << (i + 1)); 
            } 
        } 
        vector<int> possibles; 
        for(int i = 0; i < (1 << 10); i++) { 
            int now = curn; 
            for(int j = 0; j < 10; j++) { 
                if(i & (1 << j)) { 
                    now ^= op[j + 1]; 
                } 
            } 
            if(now == 2046) { 
                possibles.push_back(i); 
            } 
        } 
        int minlen = 11; 
        for(int i = 0; i < possibles.size(); i++) { 
            minlen = min(minlen, (ll)__builtin_popcountll(possibles[i])); 
        } 
        if(minlen == 11 or minlen == 0) { 
            // cout << -1 << endl; 
        } else { 
                 
            vector<string> s; 
            for(int i = 0; i < possibles.size(); i++) { 
                if(minlen == (ll)__builtin_popcountll(possibles[i])) { 
                    string res = ""; 
                    for(int j = 0; j < 10; j++) { 
                        if(possibles[i] & (1 << j)) { 
                            res += ('a' + j); 
                        } 
                    } 
                    s.push_back(res); 
                } 
            } 
            sort(s.begin(), s.end()); 
            if(s.size() >= 2) { 
                cout << fuck << ": "; 
                cout << s.size() << ": "; 
                cout << minlen << endl; 
 
                for(int o = 0; o < s.size(); o++) { 
                    cout << s[o] << " "; 
                } 
                cout << endl; 
                string ans = s[0]; 
                for(int i = 0; i < ans.size(); i++) { 
                    cout << ans[i] - 'a' + 1 << " "; 
                } 
                cout << endl << endl; 
            } 
        } 
        // cout << endl; 
    } 
    } 
    return 0; 
}