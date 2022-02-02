#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

vector<pair<int, string>> s;
int ans, n, m;

void bt(int bit, int l, string v, int ok){
    if(l == n and bit < ok) return;
    if(bit == ok){
        bool ok = 1;
        for(int i = l; i < n; i++){
            if((s[0].nd)[i] == '1') v += "0";
            if((s[0].nd)[i] == '0') v += "1";
        }
        //cout << v << "\n";
        for(int i = 1; i < m; i++){
            string t = s[i].nd;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(t[j] == v[j]) cnt++;
            }
            if(cnt != s[i].st){
                ok = 0;
                break;
            }
        }
        //if(ok) cout << v << "\n";
        ans += ok;
        return;
    }
    for(int i = l; i < n; i++){
        //cout << i << "\n";
        v += (s[0].nd)[i]; 
        bt(bit + 1, i + 1, v, ok);
        if((s[0].nd)[i] == '1') v[i] = '0';
        if((s[0].nd)[i] == '0') v[i] = '1';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    s.resize(m);
    for(int i = 0; i < m; i++){
        cin >> s[i].nd >> s[i].st;
    }
    sort(s.begin(), s.end());
    string v;
    bt(0, 0, v, s[0].st);
    cout << ans << "\n";
    return 0;
}