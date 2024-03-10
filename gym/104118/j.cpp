#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

int r, c;
pii pos[3];
char s[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    int cnt = 0;
    for(int i = 0; i < r; i++){
        cin >> s[i];
        for(int j = 0; j < c; j++){
            if(s[i][j] == '#') pos[cnt++] = {i, j};
        }
    }
    int ans = INF;
    pii how;
    for(int k = 0; k < 3; k++){
        int i = (k + 1) % 3, j = (k + 2) % 3;
        //join in same i
        if(pos[i].nd == pos[j].nd and ((pos[k].st >= pos[j].st and pos[k].st >= pos[i].st) or (pos[k].st <= pos[j].st and pos[k].st <= pos[i].st))){
            if(ans > abs(pos[i].nd - pos[k].nd) + max(abs(pos[j].st - pos[k].st), abs(pos[i].st - pos[k].st)) - 2){
                ans = abs(pos[i].nd - pos[k].nd) + max(abs(pos[j].st - pos[k].st), abs(pos[i].st - pos[k].st)) - 2;
                how = {0, k};
            }
        }
        else{
            if(ans > abs(pos[i].st - pos[k].st) + abs(pos[j].st - pos[k].st) + max({pos[i].nd, pos[j].nd, pos[k].nd}) - min({pos[i].nd, pos[j].nd, pos[k].nd}) - 2){
                ans = abs(pos[i].st - pos[k].st) + abs(pos[j].st - pos[k].st) + max({pos[i].nd, pos[j].nd, pos[k].nd}) - min({pos[i].nd, pos[j].nd, pos[k].nd}) - 2;
                how = {0, k};
            }
        }
        //join in same j
        if(pos[i].st == pos[j].st and ((pos[k].nd >= pos[j].nd and pos[k].nd >= pos[i].nd) or (pos[k].nd <= pos[j].nd and pos[k].nd <= pos[i].nd))){
            if(ans > abs(pos[i].st - pos[k].st) + max(abs(pos[j].nd - pos[k].nd), abs(pos[i].nd - pos[k].nd)) - 2){
                ans = abs(pos[i].st - pos[k].st) + max(abs(pos[j].nd - pos[k].nd), abs(pos[i].nd - pos[k].nd));
                how = {1, k};
            }
        }
        else{
            if(ans > abs(pos[i].nd - pos[k].nd) + abs(pos[j].nd - pos[k].nd) + max({pos[i].nd, pos[j].nd, pos[k].nd}) - min({pos[i].nd, pos[j].nd, pos[k].nd}) - 2){
                ans = abs(pos[i].nd - pos[k].nd) + abs(pos[j].nd - pos[k].nd) + max({pos[i].nd, pos[j].nd, pos[k].nd}) - min({pos[i].nd, pos[j].nd, pos[k].nd}) - 2;
                how = {1, k};
            }
        }
    }
    if(how.st == 0){
        int k = how.nd;
        int i = (k + 1) % 3, j = (k + 2) % 3;
        for(int x = min(pos[k].st, pos[i].st); x <= max(pos[k].st, pos[i].st); x++){
            s[x][pos[i].nd] = '#';
        }
        for(int x = min(pos[k].st, pos[j].st); x <= max(pos[k].st, pos[j].st); x++){
            s[x][pos[j].nd] = '#';
        }
        for(int x = min({pos[k].nd, pos[j].nd, pos[i].nd}); x <= max({pos[k].nd, pos[j].nd, pos[i].nd}); x++){
            s[pos[k].st][x] = '#';
        }
    }
    if(how.st == 1){
        int k = how.nd;
        int i = (k + 1) % 3, j = (k + 2) % 3;
        for(int x = min(pos[k].nd, pos[i].nd); x <= max(pos[k].nd, pos[i].nd); x++){
            s[pos[i].st][x] = '#';
        }
        for(int x = min(pos[k].nd, pos[j].nd); x <= max(pos[k].nd, pos[j].nd); x++){
            s[pos[j].st][x] = '#';
        }
        for(int x = min({pos[k].st, pos[j].st, pos[i].st}); x <= max({pos[k].st, pos[j].st, pos[i].st}); x++){
            s[x][pos[k].nd] = '#';
        }
    }
    for(int i = 0; i < r; i++) cout << s[i] << "\n";
    return 0;
}