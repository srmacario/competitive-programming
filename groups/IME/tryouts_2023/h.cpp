#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+5;

int n, q;
int trie[N][27], min_len[N], trien = 1;

int add(int u, char c){
    c -= 'a';
    if(trie[u][c]) return trie[u][c];
    return trie[u][c] = ++trien;
}

void insert(int node, const string& s, int pos){
    if(pos < s.size()){
        int nxt_node = add(node, s[pos]);
        insert(nxt_node, s, pos + 1);
    }
    min_len[node] = min(min_len[node], (int)s.size());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    memset(min_len, 63, sizeof(min_len));
    min_len[0] = -1;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(1, s, 0);
    }
    for(int i = 0; i < q; i++){
        string r;
        cin >> r;
        int cur = 1;
        for(auto ch : r) cur = trie[cur][ch - 'a'];
        if(cur == 0) cout << "-1\n";
        else cout << (min_len[cur] - r.size()) << '\n';
    }
}