#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, k, t, a[N], b, c[N], d[N], e;
multiset<int> l, f;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            c[i] = false;
        l.clear();
        f.clear();

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            d[a[i]] = i;
        }
        int ll = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &b);
            while(ll < n && a[ll] != b)
                ll++;
            c[b] = true;
        }
        for(int i = 0; i < k; i++){
            scanf("%d", &e);
            l.insert(e);
        }

        if(ll == n){
            printf("NO\n");
            continue;
        }
        f.insert(-1);
        f.insert(n);
        for(int i = n; i >= 0; i--){
            if(i == 0){
                printf("YES\n");
                break;
            }
            if(!c[i]){
                auto lb = f.lower_bound(d[i]);
                int ma = *lb;
                lb--;
                ma -= *lb;
                ma--;
                lb = l.upper_bound(ma);
                if(lb == l.begin()){
                    printf("NO\n");
                    break;
                }
                lb--;
                l.erase(lb);
            }
            f.insert(d[i]);
        }
    }
    return 0;
}