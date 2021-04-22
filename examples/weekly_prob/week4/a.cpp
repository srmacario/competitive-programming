#include <bits/stdc++.h>

using namespace std;

const int K = 52;
const int N = 1005;

int idc(char c){
    if(c < 'a') return c - 'A' + 26;
    else return c - 'a';
}

struct Aho{

    struct Vertex{
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        bitset<N> ids;

        Vertex(int par = -1, char ch = '$', int id = -1) : p(par), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };  

    vector<Vertex> t;

    Aho() : t(1){}

    void add_string(const string& s, int id){
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            if(t[v].next[c] == -1){
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].ids.set(id);
    }

    int get_link(int v){
        if(t[v].link == -1){
            if(v == 0 || t[v].p == 0) t[v].link = 0;
            else t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch){
        int c = idc(ch);
        if(t[v].go[c] == -1){
            if(t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
            else t[v].go[c] = (v == 0) ? 0 : go(get_link(v), ch);
            t[v].ids |= t[t[v].go[c]].ids;
        }
        return t[v].go[c];
    }

    bitset<N> run(const string& s){
        bitset<N> bs;
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            bs |= t[v].ids;
            v = go(v, ch);
        }
        bs |= t[v].ids;
        return bs;
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int k;
    string s;
    cin >> k;
    while(k--){
        int q;
        cin >> s >> q;
        Aho aho;
        for(int i = 0; i < q; i++){
            string x;
            cin >> x;
            aho.add_string(x, i);
        }
        auto ans = aho.run(s);
        for(int i = 0; i < q; i++) printf("%c\n", ans[i] ? 'y' : 'n');
    }
    return 0;
}