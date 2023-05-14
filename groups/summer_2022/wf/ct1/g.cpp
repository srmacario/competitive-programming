#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 1e6 + 5;

int m, n, A, B;*

vector <piii> pts;

struct segTreeNode{int mx; set <int> num;};
int v[N];
segTreeNode st[4*N];

void merge(int p){
    st[p].mx = max(st[2*p].mx, st[2*p + 1].mx);
}

int a, b, C = ~(1<<31), M = (1<<16) - 1;

int r(){
    a = 36939 * (a & M) + (a >> 16);
    b = 18000 * (b & M) + (b >> 16);
    return (C & ((a << 16) + b)) % 1000000;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> m >> n >> A >> B;
        a = A, b = B;
        if(!m and !n and !a and !b) return 0;
        for(int i = 0; i < m; i++) cin >> pts[i].st >> pts[i].nd.st >> pts[i].nd.nd;
        for(int i = 0; i < n; i++){
            pts[m + i].st = r();
            pts[m + i].nd.st = r();
            pts[m + i].nd.nd = r();
        }
        sort(pts.begin(), pts.end());
        for(int i = 0; i < m + n; i++){
            
        }
    }

    return 0;
}