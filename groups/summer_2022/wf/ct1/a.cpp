#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

const int N = 1e6 + 5, M = 2e3 + 5;
const int MOD = 1e9 + 9;
ull h[M][M], p[N];
ull pr = 1777771;
string f[N], m[N];
int cnt;

void build_p(){
    p[0] = 1, p[1] = pr;
    for(int i = 1; i < N; i++){
        p[i] = (p[1]*p[i - 1]) % MOD;
    }
}

void build (string &s, int id){
    for(int i = 1; i <= s.size(); i++){
        h[id][i] = ((p[1]*h[id][i - 1]) % MOD + s[i - 1]) % MOD;
    }
}

//1 - indexed
ull fhash(int l, int r, int id){
    return (h[id][r] - ((h[id][l-1] * p[r-l+1]) % MOD) + MOD) % MOD; 
}

ull shash(string &pt){
    ull h = 0;
    for(int i = 0; i < pt.size(); i++)
        h = ((h * pr) %  MOD + pt[i]) % MOD;
    return h;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int hp, wp, hm, wm;
    while(cin >> hp >> wp >> hm >> wm){
        ull cur = 0;
        for(int i = 0; i < hp; i++){
            cin >> f[i];
            cur = (cur + (shash(f[i]) * p[wp * (hp - i - 1)]) % MOD) % MOD;
        }
        for(int i = 0; i < hm; i++){
            cin >> m[i];
            build(m[i], i);
        }
        for(int j = 0; j + wp < wm; j++){
            ull tmp = 0;
            for(int i = 0; i < hp; i++){
                tmp = (tmp + (fhash(j + 1, wp + j, i) * p[wp * (hp - i - 1)]) % MOD) % MOD;
            }
            for(int i = hp; i < hm; i++){
                tmp = (tmp - (fhash(j + 1, wp + j, ) )
            }
        }
    }
    return 0;
}