#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int cc[N], cr[N], ans, n, q;
char s[N][N];
deque<int> d[N];

void chg(int i, int j, int b){
    if(d[i][j]){
        if(cc[j] == n)
            ans--;
        if(cr[i] == n)
            ans--;
        cc[j]--;
        cr[i]--;
    }
    d[i][j] = b;
    if(b){
        cc[j]++;
        cr[i]++;
        if(cc[j] == n)
            ans++;
        if(cr[i] == n)
            ans++;
    }
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf(" %s", s[i]);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        int x = (s[i][j] - '0');
        d[i].push_back(x);
        cc[j] += x;
        cr[i] += x;
    }
    for(int i = 0; i < n; i++){
        ans += (cc[i] == n);
        ans += (cr[i] == n);
    }
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int i, j, b;
            scanf("%d %d %d", &i, &j, &b);
            chg(i - 1, j - 1, b);
        }
        else{
            int prv;
            scanf("%d", &prv);
            if(cc[n - 1] == n)
                ans--;
            for(int j = n - 1; j; j--)
                cc[j] = cc[j - 1];
            cc[0] = 0;
            for(int i = 0; i < n; i++){
                int h = d[i].back();
                d[i].pop_back();
                cc[0] += prv;
                d[i].push_front(prv);
                if(prv > h){
                    cr[i]++;
                    if(cr[i] == n)
                        ans++;
                }
                else if(prv < h){
                    if(cr[i] == n)
                        ans--;
                    cr[i]--;
                }
                prv = h;
            }
            ans += (cc[0] == n);
        }
        printf("%d\n", ans);
    }
    return 0;
}