#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int a[N];

int main(){
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            int dif = 0;
            for(int i = l; i <= r; i++){
                if(a[i] == 1) dif--;
                else dif++;
            }
            ans = max(ans, sum + dif);
        }
    }
    printf("%d\n", ans);
    return 0;
}