#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl '\n'
#define double long double
#define int long long

const int N = 2e6 + 5;

int lps[N];

void prekmp(string &p){
    for(int i = 1, j = 0; i < p.size(); i++){
        while(j and p[j] != p[i]) j = lps[j - 1];
        if(p[j] == p[i]) j++;
        lps[i] = j;
    }
}
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<string>> v(n, vector<string>(n));
    vector<vector<int>> sz(n, vector<int> (n, 0));
    bool ok1 = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            sz[i][j] = v[i][j].size();
            if(j < i and v[i][j].size() != v[j][i].size()){
                ok1 = false;
            }
            if(sz[i][j] == 1 && i != j) {
                ok1 = false;
            }
        }
    }
    if(!ok1) {
        cout << "NONE" << endl;
        return 0;
    } 
    // precisa ver n = 2
    if(n == 2) {
        if(v[0][1].size() != v[1][0].size()){
            cout << "NONE" << endl;
            return 0;
        }
        string s = v[0][1] + "#" + v[1][0];
        prekmp(s);
        int l1 = lps[s.size() - 1];
        int l2 = v[0][1].size() - l1;
        if(l2 == 0){
            int period = v[0][1].size() - lps[v[0][1].size() - 1];
            if(!(v[0][1].size() % period)){
                int k = v[0][1].size() / period;
                if(k == 1){
                    cout << "NONE" << endl;
                    return 0;
                }
                if(k == 2){
                    cout << "UNIQUE" << endl;
                    cout << v[0][1].substr(0, period) << endl;
                    cout << v[0][1].substr(0, period) << endl;
                    return 0;
                }
                cout << "MANY\n";
                return 0;
            }
            cout << "NONE" << endl;
            return 0;
        }
        else{
            string s1 = v[0][1].substr(0, l1), s2 = v[1][0].substr(0, l2);
            if(v[0][1] != s1 + s2 or v[1][0] != s2 + s1){
                cout << "NONE" << endl;
                return 0;
            }
            cout << "UNIQUE" << endl;
            cout << s1 << endl;
            cout << s2 << endl;
        }
        return 0;
    }
    map<int, int> possible[n];
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int x = v[i][j].size(),
                    y = v[j][k].size(),
                    z = v[i][k].size();
                
                int si_2SZ = z + x - y;
                int sj_2SZ = x + y - z;
                int sk_2SZ = y + z - x;
                if(si_2SZ & 1 or sj_2SZ & 1 or sk_2SZ & 1 or si_2SZ <= 0 or sj_2SZ <= 0 or sk_2SZ <= 0) {
                    ok = false;
                    i = j = k = n;
                    break;
                }
                possible[i][si_2SZ / 2]++;
                possible[j][sj_2SZ / 2]++;
                possible[k][sk_2SZ / 2]++;
                if(possible[i].size() > 1 or possible[j].size() > 1 or possible[k].size() > 1) {
                    ok = false;
                    i = j = k = n;
                    break;
                }
            }
        }
    }
    if(!ok) {
        cout << "NONE" << endl;
        return 0;
    }
    map<int, string> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            auto itrLeft = possible[i].begin();
            auto itrRight = possible[j].begin();
            string left = v[i][j].substr(0, itrLeft->first);
            string right = v[i][j].substr(itrLeft->first);
            if(!mp.count(i)) {
                mp[i] = left;
            } else {
                ok *= (mp[i] == left);
                if(!ok) {
                    i = j = n;
                    break;
                }
            }
            if(!mp.count(j)) {
                mp[j] = right;
            } else {
                ok *= (mp[j] == right);
                if(!ok) {
                    i = j = n;
                    break;
                }
            }
        }
    }
    if(!ok) {
        cout << "NONE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for(auto e : mp) {
            cout << e.second << endl;
        }
    }
}
/*
3
* difaik difhammarby
aikdif * aikhammarby
hammarbydif hammarbyaik *
 

bumdwbumdwbumdwbumdw # wbumdwbumd

*/