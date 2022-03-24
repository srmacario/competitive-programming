#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int N = 2e5 + 5;

int n;
long double a[N], ma[N], mar[N], mi[N], mir[N];

int main() {
    scanf("%d", &n);
    mi[1] = 1e9;
    mir[n + 1] = 1e9;
    for(int i = 1; i <= n; i++){
        scanf("%Lf", &a[i]);
        if(i > 1){
            ma[i] = max(ma[i - 1], a[i - 1]);
            mi[i] = min(mi[i - 1], a[i - 1]);
        }
    }
    for(int i = n; i; i--){
        mar[i] = max(mar[i + 1], a[i]);
        mir[i] = min(mir[i + 1], a[i]);
    }
    printf("1");
    for(int i = 2; i <= n; i++){
        printf(" %.9Lf", 
        max({(ld)0, (ld)1.0 - ma[i] / mar[i], 
        (ld)1.0 - mi[i] / mir[i]}));
    }
    printf("\n");
}