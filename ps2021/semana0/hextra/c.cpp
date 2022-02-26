#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main(){
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i = 0; i < k; i++) ans += a[i];
    printf("%d\n", ans);
    return 0;
}