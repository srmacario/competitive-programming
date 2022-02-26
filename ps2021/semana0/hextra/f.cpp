#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int l[N];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }
    sort(l, l+n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                //desigualdade triangular basta comparar a do maior lado
                //por isso a ordenação antes
                if(l[k] < l[i] + l[j] and (l[k] != l[j]) and (l[k] != l[i]) and (l[i] != l[j])){
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}