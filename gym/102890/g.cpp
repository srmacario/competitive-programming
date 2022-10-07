#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], g[N], n;
vector<int> evt[N], evb[N];
multiset<int> ms;

int calc(int p = 0){
    for(int i : evb[p])
        ms.insert(i);
    if(p == n){
        if(ms.empty())
            return 0;
        auto lb = ms.end();
        lb--;
        return *lb;
    }
    int h = 0;
    if(!ms.empty()){
        auto lb = ms.end();
        lb--;
        h = *lb;
    }
    evb[min(p + a[p], n)].push_back(g[p] + h);
    evt[min(p + b[p], n)].push_back(g[p] + h);
    for(int i : evt[p])
        ms.erase(ms.lower_bound(i));
    return calc(p + 1);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &g[i], &a[i], &b[i]);
    printf("%d\n", calc());
    return 0;
}