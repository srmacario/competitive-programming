#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 25;

int n, g, p[N], tot;
vector<pii> v[N];

int main(){
    scanf("%d %d", &n, &g);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        tot += p[i];
    }
    for(int i = 0; i < (1 << n); i++){
        int h = 0;
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                h += p[j];
        h = 100 * h / tot;
        if(h >= g)
            v[__builtin_popcount(i)].push_back({h, i});
    }
    for(int i = 0; i <= n; i++)
        if(!v[i].empty()){
            printf("%d %d\n", i, v[i].size());
            for(pii j : v[i]){
                printf("%d", j.st);
                for(int k = 0; k < n; k++)
                    if(j.nd & (1 << k))
                        printf(" %d", k + 1);
                printf("\n");
            }
            return 0;
        }
    return 0;
}